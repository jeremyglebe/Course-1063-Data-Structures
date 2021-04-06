#include <iostream>
#include <fstream>
#include "Storybook.h"

string replace_all(string text, string from, string to)
{
    size_t start_pos = 0;
    // While we can find the substring "from"
    // (start position changes each time we make a replacement)
    while ((start_pos = text.find(from, start_pos)) != string::npos)
    {
        // Make the replacement
        text.replace(start_pos, from.length(), to);
        // Move past the string replacement's length, we don't need to
        // check it
        start_pos += to.length();
    }
    return text;
}

Choice::Choice()
{
    body = "";
    nextPageIndex = 0;
}

Choice::Choice(string body, int nextPageIndex)
{
    this->body = body;
    this->nextPageIndex = nextPageIndex;
}

string Choice::getBody()
{
    return body;
}

int Choice::getNextIndex()
{
    return nextPageIndex;
}

void Choice::setBody(string body)
{
    this->body = body;
}

void Choice::setNextIndex(int nextPageIndex)
{
    this->nextPageIndex = nextPageIndex;
}

Page::Page()
{
    body = "";
    numChoices = 1;
    choices = new Choice *[1];
    choices[1] = nullptr;
}

Page::Page(string body, int numChoices)
{
    this->body = body;
    this->numChoices = numChoices;
    choices = new Choice *[numChoices];
    for (int i = 0; i < numChoices; i++)
    {
        choices[i] = nullptr;
    }
}

Page::~Page()
{
    for (int i = 0; i < numChoices; i++)
    {
        if (choices[i] != nullptr)
        {
            delete choices[i];
        }
    }
    delete choices;
}

string Page::getBody()
{
    return body;
}

Choice *Page::getChoice(int i)
{
    return choices[i];
}

int Page::getNumChoices()
{
    return numChoices;
}

void Page::setBody(string body)
{
    this->body = body;
}

void Page::setChoice(int i, Choice *c)
{
    choices[i] = c;
}

Storybook::Storybook()
{
    numPages = 1;
    pages = new Page *[1];
    pages[0] = nullptr;
}

Storybook::Storybook(int numPages)
{
    this->numPages = numPages;
    pages = new Page *[numPages];
    for (int i = 0; i < numPages; i++)
    {
        pages[i] = nullptr;
    }
}

Storybook::Storybook(string filename)
{
    // Open a file
    ifstream ifile(filename);
    // Read in the number of pages
    ifile >> numPages;
    // Create the array of pages
    pages = new Page *[numPages];
    for (int i = 0; i < numPages; i++)
    {
        pages[i] = nullptr;
    }
    // Process each page
    for (int p = 0; p < numPages; p++)
    {
        // Get the number of lines in the body
        int numLines;
        ifile >> numLines;
        // Ignore leftover newline from ifile usage
        ifile.get();
        // Read in the body from the file
        string body = "";
        for (int l = 0; l < numLines; l++)
        {
            // Create a temporary variable to store the line in
            string line;
            // Get the next line from the file
            getline(ifile, line);
            // Add the line to the page body
            body += line + '\n';
        }
        // Now get the number of choices
        int numChoices;
        ifile >> numChoices;
        // Ignore leftover newline from ifile usage
        ifile.get();
        // Create the Page object
        pages[p] = new Page(body, numChoices);
        // Read in the pages choices from the file
        for (int c = 0; c < numChoices; c++)
        {
            // Get the choice's body
            string chBody;
            getline(ifile, chBody);
            // Get the index of the page that this choice leads to
            int nextPageIndex;
            ifile >> nextPageIndex;
            // Ignore leftover newline from ifile usage
            ifile.get();
            // Create the choice object
            pages[p]->setChoice(c, new Choice(chBody, nextPageIndex));
        }
    }
    // Close the file
    ifile.close();
}

Storybook::~Storybook()
{
    for (int i = 0; i < numPages; i++)
    {
        if (pages[i] != nullptr)
        {
            delete pages[i];
        }
    }
    delete pages;
}

void Storybook::findAndReplace(string key, string replace)
{
    // Check every page
    for (int p = 0; p < numPages; p++)
    {
        // Replace all instances in the page's body
        pages[p]->setBody(replace_all(pages[p]->getBody(), key, replace));
        // Check all of the pages choices
        for (int ch = 0; ch < pages[p]->getNumChoices(); ch++)
        {
            // Just another reference to the choice object
            Choice *choice = pages[p]->getChoice(ch);
            // Replace all instances in the choice's body
            choice->setBody(replace_all(choice->getBody(), key, replace));
        }
    }
}

Page *Storybook::getPage(int i)
{
    return pages[i];
}

int Storybook::getNumPages()
{
    return numPages;
}

void Storybook::setPage(int i, Page *p)
{
    pages[i] = p;
}