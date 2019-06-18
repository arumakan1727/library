#include "bits/stdc++.h"
#include "cmdline.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

static const string SNIPPET_SEGMENT("//@@@");

// Exception Classes {{{
class FileNotFoundException : public std::exception {
private:
    const string fileName;

public:
    explicit FileNotFoundException(const string &fileName)
        : fileName(fileName + " : Not Found") {}

    ~FileNotFoundException() {}

    const char* what() const noexcept override { return fileName.c_str(); }
};

class SnippetFormatException : public std::exception {
private:
    const string msg;

public:
    explicit SnippetFormatException(const string &s)
        : msg(s) {}

    ~SnippetFormatException() {}

    const char* what() const noexcept override { return msg.c_str(); }
};
// }}}

// Snippet {{{
class Snippet {
private:
    string snippetName;
    string abbr;
    string alias;
    string options;
    vector<string> lines;

#define tee_printf(out_fp, ...)   do { fprintf(out_fp, __VA_ARGS__); printf(__VA_ARGS__); }while(0)

public:

    void append(const char *line) {
        lines.emplace_back(line);
    }

    const vector<string>& getLines() const {
        return lines;
    }

    void setName(const string &s) {
        snippetName = s;
    }

    void setAbbr(const string &s) {
        abbr = s;
    }

    void addAlias(const string &s) {
        alias += s + " ";
    }

    void addOption(const string &s) {
        options += s + " ";
    }

    void clear() {
        snippetName.clear();
        abbr.clear();
        alias.clear();
        options.clear();
        lines.clear();
    }

    void writeSnip(FILE *out_fp) const {
        printf("\n");

        tee_printf(out_fp, "%-10s  %s\n", "snippet", snippetName.c_str());
        if (!abbr.empty()) tee_printf(out_fp, "%-10s  %s\n", "abbr", abbr.c_str());
        if (!alias.empty()) tee_printf(out_fp, "%-10s  %s\n", "alias", alias.c_str());
        if (!options.empty()) tee_printf(out_fp, "%-10s  %s\n", "options", options.c_str());

        for (const string &line : lines) {
            tee_printf(out_fp, "    %s\n", line.c_str());
        }
        tee_printf(out_fp, "\n\n");
    }

    bool invalidState() const {
        return snippetName.empty() || lines.empty();
    }

};
// }}}

bool startsWith(const string &s, const string &w);

string baseName(const string &fileName);

bool isWritableDir(const string &dir);

bool isAllReadable(const vector<string> &pathList, string &errFileName);

vector<string> splitToken(const string &s);

void genSnip(const string &src, const string &outDir);

void test_startsWith();
void test_baseName();
void test_splitToken();

/////////////////////////////////////////////////////////////////////
// main()
//
signed main(int argc, char *argv[])
{

#ifdef TEST

    test_startsWith();
    test_baseName();
    test_splitToken();
    puts("test : All Accepted.");
    return 0;

#endif

    cmdline::parser parser;
    parser.add<string>("out-dir", 'd', "Output Directory of SnippetFile", false, ".");
    parser.parse_check(argc, argv);

    const string outDir = parser.get<string>("out-dir");


    // option check {{{
    try {

        if (parser.rest().size() <= 0) {
            fprintf(stderr, "[Error] スニペット元となるソースファイルを1つ以上指定してください\n");
            exit(1);
        }

        if (!isWritableDir(outDir)) {
            fprintf(stderr, "[Error] 不当なディレクトリ `%s` : 書き込み可能なディレクトリを指定してください\n",
                    outDir.c_str());
            exit(1);
        }

        string unReadableFileName;
        if (!isAllReadable(parser.rest(), unReadableFileName)) {
            fprintf(stderr, "[Error] 不当なファイル `%s` : このファイルは読み込みできません\n",
                    unReadableFileName.c_str());
            exit(1);
        }
    } catch (const FileNotFoundException &e) {
        fprintf(stderr, "[Error] %s\n", e.what());
        exit(8);
    }
    // }}}

    for (int i = 0; i < parser.rest().size(); ++i) {
        const string &src = parser.rest()[i];
        printf("\nproccessing `%s` .\n", src.c_str());
        try  {
            genSnip(src, outDir);
        } catch (const SnippetFormatException &e)  {
            fprintf(stderr, "[Error] %s : %s\n", src.c_str(), e.what());
            exit(1);
        }
    }

    return 0;
}

//////////////////////////////////////////////////////////////////////
// startsWith()
//
bool startsWith(const string &s, const string &w)
{
    return s.find(w) == 0;
}

//////////////////////////////////////////////////////////////////////
// startsWith()
//
string baseName(const string &fileName)
{
    int lastDotPos = fileName.length();
    int lastPathDelim = -1;

    for (int i = 0; i < fileName.length(); ++i) {
        if (i > 0 && fileName[i] == '.') lastDotPos = i;
        else if (fileName[i] == '/') lastPathDelim = i;
    }
    return fileName.substr(lastPathDelim + 1, lastDotPos - (lastPathDelim + 1));
}

//////////////////////////////////////////////////////////////////////
// isWritableDir()
//
bool isWritableDir(const string &dir)
{
    struct stat st;

    if (stat(dir.c_str(), &st) != 0) {
        throw FileNotFoundException(dir);
    }

    // ディレクトリ かつ アクセス可能 かつ 書き込み可能 かどうか調べる
    return
        S_ISDIR(st.st_mode) &&
        (st.st_uid == getuid()) &&
        (st.st_mode & S_IXUSR) &&
        (st.st_mode & S_IWUSR);
}

//////////////////////////////////////////////////////////////////////
// isAllReadable()
//
bool isAllReadable(const vector<string> &pathList, string &errFileName)
{
    struct stat st;
    for (const auto &path : pathList) {
        if (stat(path.c_str(), &st) != 0) {
            throw FileNotFoundException(path);
        }

        if ((st.st_uid != getuid()) || !S_ISREG(st.st_mode) || !(st.st_mode & S_IRUSR)) {
            errFileName = path;
            return false;
        }
    }
    return true;
}


//////////////////////////////////////////////////////////////////////
// splitToken()
//
vector<string> splitToken(const string &s)
{
    char buf[256];
    const char *p = s.c_str();

    vector<string> tokens;
    while(sscanf(p, "%s", buf) > 0) {
        tokens.emplace_back(buf);
        while(isspace(*p)) ++p;
        p += strlen(buf);
    }

    return tokens;
}

//////////////////////////////////////////////////////////////////////
// startsWith()
//
void genSnip(const string &src, const string &outDir)
{
    vector<Snippet> snippets;

    bool inSnippet = false;
    char line[256];
    FILE *in_fp = fopen(src.c_str(), "r");

    if (in_fp == NULL) {
        fprintf(stderr, "%s : File Read Faild.\n", src.c_str());
        exit(3);
    }

    Snippet snip;

    while(fgets(line, sizeof(line), in_fp) != NULL) {
        printf("inSnippet: %d  ", inSnippet);
        fputs(line, stdout);
        line[strlen(line) - 1]= '\0';
        const auto tokens = splitToken(line);

        if (tokens.empty()) {
            if (inSnippet) snip.append("");
        }
        else if (startsWith(tokens[0], SNIPPET_SEGMENT)) {

            if (inSnippet) {
                snippets.emplace_back(move(snip));
                snip = Snippet();
                inSnippet = false;
            } else {
                snip.clear();
                inSnippet = true;
            }

        } else if (startsWith(tokens[0], "//@")) {
            if (tokens.size() < 3) {
                throw SnippetFormatException("Invlaid Snippet Format");
            }

            const string &op = tokens[1];
            if (op == "snippet") {
                if (tokens.size() != 3)
                    throw SnippetFormatException("Invlaid Snippet Name");
                snip.setName(tokens[2]);
                printf("setName: %s\n", tokens[2].c_str());
            }
            else if (op == "abbr") {
                if (tokens.size() != 3)
                    throw SnippetFormatException("Invlaid Abbr Name");
                snip.setAbbr(tokens[2]);
                printf("setAbbr: %s\n", tokens[2].c_str());
            }
            else if (op == "alias") {
                if (tokens.size() < 3)
                    throw SnippetFormatException("Invlaid Alias Name");
                for (int i = 2; i < tokens.size(); ++i) {
                    snip.addAlias(tokens[i]);
                    printf("addAlias: %s\n", tokens[i].c_str());
                }
            }
            else if (op == "options") {
                if (tokens.size() < 3)
                    throw SnippetFormatException("Invlaid Option Name");
                for (int i = 2; i < tokens.size(); ++i) {
                    snip.addOption(tokens[i]);
                    printf("addOptions: %s\n", tokens[i].c_str());
                }
            }
            else {
                fclose(in_fp);
                throw (SnippetFormatException(op + " : Unknown Snippet Option"));
            }
        } else {
            if (inSnippet) {
                snip.append(line);
            }
        }
    }

    if (inSnippet) {
        fclose(in_fp);
        throw (SnippetFormatException("スニペットの終端記号 `//@@@` がありません" ));
    }

    if (any_of(snippets.begin(), snippets.end(), [](const auto &e) { return e.invalidState(); })) {
        fclose(in_fp);
        throw SnippetFormatException("[Error] SnippetName or Body is Empty.");
    }

    const string outFileName = outDir + "/" + baseName(src) + ".snip";
    FILE *out_fp = fopen(outFileName.c_str(), "w");
    printf("outFileName = `%s`\n", outFileName.c_str());

    if (out_fp == NULL) {
        fclose(in_fp);
        fprintf(stderr, "[Error] %s : FileOpen Faild.\n", outFileName.c_str());
        exit(3);
    }

    for (const auto &e : snippets) {
        e.writeSnip(out_fp);
    }

    fclose(in_fp);
    fclose(out_fp);
    return;
}


// tests {{{
void test_startsWith()
{
    assert(startsWith("abc", "a") == true);
    assert(startsWith("abc", "abc") == true);
    assert(startsWith("abc", "") == true);
    assert(startsWith("abc", "b") == false);
    assert(startsWith("abc", "bc") == false);
}

void test_baseName()
{
    assert(baseName("./hoge.cpp") == "hoge");
    assert(baseName("/./././hoge") == "hoge");
    assert(baseName("/hoge.") == "hoge");
    assert(baseName("library/hoge.ini.cpp") == "hoge.ini");
    assert(baseName(".bashrc") == ".bashrc");
}

void test_splitToken()
{
    const auto x = splitToken("//@ snippets UnionFind  ");
    for (const auto &e : x) cout << e << endl;

    vector<string> a {"//@", "snippets", "UnionFind"};
    assert(splitToken("  //@ snippets UnionFind") == a);
    assert(splitToken("//@ snippets UnionFind  ") == a);
}
// }}}
