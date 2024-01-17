#include <iostream>
using namespace std;

struct node
{
    int col;
    int val;
    struct node *next;
};

class SparseMatrix
{
private:
    int row, col;
    node** arr;

public:
    SparseMatrix(int row, int col)
    {
        this->row = row;
        this->col = col;

        arr = new node *[row];
        for (int i = 0; i < row; i++)
            arr[i] = nullptr;
    }

    void insert(int row, int col, int val)
    {
        node *newNode = new node;
        newNode->col = col;
        newNode->val = val;
        newNode->next = nullptr;

        if (arr[row] == nullptr)
        {
            arr[row] = newNode;
        }
        else
        {
            node *temp = arr[row];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display()
    {
        for (int i = 0; i < row; i++)
        {
            node *p = arr[i];
            for (int j = 0; j < col; j++)
            {
                if (p!=nullptr && p->col == j)
                {
                    cout << p->val << " ";
                    p = p->next;
                }
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};

int main()
{

    int row, col, in;
    cout << "Enter the no. of rows and columns: ";
    cin >> row >> col;
    SparseMatrix SparseMatrix(row, col);

    cout << "Enter the elements: ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> in;
            if (in != 0)
            {
                SparseMatrix.insert(i, j, in);
            }
        }
    }

    cout << "Sparse Matrix Representation:" << endl;
    SparseMatrix.display();

    return 0;
}