#include <string>
#include <unordered_map>

using namespace std;

class Spreadsheet
{
public:
    unordered_map<int, int> m_sheet;

    Spreadsheet(int rows)
    {
    }

    void setCell(string cell, int value)
    {
        m_sheet[get_cell_index(cell)] = value;
    }

    void resetCell(string cell)
    {
        m_sheet[get_cell_index(cell)] = 0;
    }

    int getValue(string formula)
    {
        int num1 = 0;
        int start1 = 1;
        int end1 = formula.find('+', start1);
        if (formula[start1] >= 'A' && formula[start1] <= 'Z')
        {
            num1 = m_sheet[get_cell_index(formula, start1, end1)];
        }
        else
        {
            num1 = my_stoi(formula, start1, end1);
        }

        int num2 = 0;
        int start2 = end1 + 1;
        int end2 = formula.size();
        if (formula[start2] >= 'A' && formula[start2] <= 'Z')
        {
            num2 = m_sheet[get_cell_index(formula, start2, end2)];
        }
        else
        {
            num2 = my_stoi(formula, start2, end2);
        }

        return num1 + num2;
    }

    int get_cell_index(const string &cell)
    {
        return get_cell_index(cell, 0, cell.size());
    }

    int get_cell_index(const string &cell, int start, int end)
    {
        int col = cell[start] - 'A';
        int row = my_stoi(cell, start + 1, end) - 1;
        return row * 26 + col;
    }

    int my_stoi(const string &text, int start, int end)
    {
        int num = 0;
        for (int i = start; i < end; ++i)
        {
            num = num * 10 + (text[i] - '0');
        }
        return num;
    }
};
