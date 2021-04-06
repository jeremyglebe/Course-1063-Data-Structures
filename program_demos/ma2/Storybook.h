#include <string>
using namespace std;

class Choice
{
public:
    Choice();
    Choice(string body, int nextPageIndex);
    // Getters
    string getBody();
    int getNextIndex();
    // Setters
    void setBody(string body);
    void setNextIndex(int nextPageIndex);

private:
    string body;
    int nextPageIndex;
};

class Page
{
public:
    Page();
    Page(string body, int numChoices);
    ~Page();
    // Getters
    string getBody();
    Choice *getChoice(int i);
    int getNumChoices();
    // Setters
    void setBody(string body);
    void setChoice(int i, Choice *c);

private:
    string body;
    Choice **choices;
    int numChoices;
};

class Storybook
{
public:
    Storybook();
    Storybook(int numPages);
    Storybook(string filename);
    ~Storybook();
    void findAndReplace(string key, string replacement);
    // Getters
    Page *getPage(int i);
    int getNumPages();
    // Setters
    void setPage(int i, Page *p);

private:
    Page **pages;
    int numPages;
};