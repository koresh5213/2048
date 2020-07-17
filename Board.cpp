#include "Board.h"
#include <stdexcept>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

Board::Board(unsigned short size)
: m_size(size)
{
    unsigned long** rows = new unsigned long*[size];
    for (unsigned short index=0; index < size; ++index)
    {
        rows[index] = new unsigned long[size];
    }
    m_board = rows;

    ClearBoard();
}

Board::~Board()
{
    for (unsigned short index=0; index < m_size; ++index)
    {
        delete[] m_board[index];
    }
    delete[] m_board;
}

unsigned long Board::GetTile(unsigned short row,unsigned short col)const
{
    if (row >= m_size || col >= m_size)
    {
        throw std::out_of_range("");
    }
    return m_board[row][col];
}

void Board::SetTile(unsigned short row, unsigned short col ,unsigned long newVal)
{
    if (row >= m_size || col >= m_size)
    {
        throw std::out_of_range("");
    }
    m_board[row][col] = newVal;
}

void Board::PrintBoard()const
{
    unsigned long max = 0;
    unsigned long spaces=0;
    unsigned long curSpaces=0;

    for (unsigned short index=0; index < m_size; ++index)
    {
        for (unsigned short jindex=0; jindex < m_size; ++jindex)
        {
            if (max < m_board[index][jindex])
            {
                max = m_board[index][jindex];
            }
        }
    }

    spaces = NumOfDigits(max);  

    for (unsigned short index=0; index < m_size; ++index)
    {
        for (unsigned short jindex=0; jindex < m_size; ++jindex)
        {
            cout << m_board[index][jindex];

            curSpaces = spaces - NumOfDigits(m_board[index][jindex]); 

                for (unsigned long kindex=0; kindex < curSpaces; kindex++)
                {
                    cout << " ";
                }
            cout << "|" ;
        }
        cout << endl;
    }
}

void Board::ClearBoard()
{
    for (unsigned short index=0; index < m_size; ++index)
    {
        for (unsigned short jindex=0; jindex < m_size; ++jindex)
        {
            m_board[index][jindex] = 0;
        }
    }
}

unsigned short Board::Size()const
{
    return m_size;
}

unsigned short Board::NumOfDigits(unsigned long n)const
{
    unsigned long counter = 1;
    while (n > 10)
    {
        counter++;
        n = n/10;
    }
    return counter;
}