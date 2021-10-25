
#include <iostream>
#include <stack>
using namespace std;

class Stroke
{
    stack<char> st_primary;
    stack<char> st_secondary;

public:
    void display_screen() //display current sreen status of stokes
    {
        stack<char> temp;
        while (!st_primary.empty())
        {
            temp.push(st_primary.top());
            st_primary.pop();
        }
        cout << "---> ";
        while (!temp.empty())
        {
            cout << temp.top();
            st_primary.push(temp.top());
            temp.pop();
        }
        cout << " <---\n\n";
    }
    void draw()
    {
        cout << "Enter the new stroke character\n";
        char x;
        cin >> x;
        st_primary.push(x);
        display_screen();
    }
    void erase()
    {
        st_primary.pop();
        display_screen();
    }
    void undo()
    {
        st_secondary.push(st_primary.top());
        st_primary.pop();
        display_screen();
    }
    void redo()
    {
        if (!st_secondary.empty())
        {
            st_primary.push(st_secondary.top());
            st_secondary.pop();
        }
        display_screen();
    }
    void play()
    {
        int flag = 1;
        while (flag)
        {
            char val;
            cout << "1 for draw\n";
            cout << "2 for erase\n";
            cout << "3 for undo\n";
            cout << "4 for redo\n";
            cout << "5 for exit\n\n";
            cout << "Enter option\n";
            cin >> val;
            switch (val)
            {
            case '1':
                this->draw();
                break;
            case '2':
                this->erase();
                break;
            case '3':
                this->undo();
                break;
            case '4':
                this->redo();
                break;
            case '5':
                cout << "EXIT \n";
                flag = 0;
                break;
            default:
                cout << "Invalid Option \n";
                break;
            }
        }
    }
};
int main()
{
    class Stroke artist1; 
    artist1.play();
}