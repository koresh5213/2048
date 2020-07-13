#include "Board.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Board::Board(unsigned short size)
: m_size(size)
{
    unsigned short** rows = new unsigned short*[size];
    for (int index=0; index < size; ++index)
    {
        rows[index] = new unsigned short[size];
    }
    m_board = rows;

    ClearBoard();
}

Board::~Board()
{
    for (int index=0; index < m_size; ++index)
    {
        delete[] m_board[index];
    }
    delete[] m_board;
}

unsigned short Board::GetTile(unsigned short row,unsigned short col)const
{
    if (row >= m_size || col >= m_size)
    {
        throw std::out_of_range("");
    }
    return m_board[row][col];
}

void Board::SetTile(unsigned short row, unsigned short col ,unsigned short newVal)
{
    if (row >= m_size || col >= m_size)
    {
        throw std::out_of_range("");
    }
    m_board[row][col] = newVal;
}

void Board::PrintBoard()const
{
    for (int index=0; index < m_size; ++index)
    {
        for (int jindex=0; jindex < m_size; ++jindex)
        {
            cout << m_board[index][jindex] << "|" ;
        }
        cout << endl;
    }
}

void Board::ClearBoard()
{
    for (int index=0; index < m_size; ++index)
    {
        for (int jindex=0; jindex < m_size; ++jindex)
        {
            m_board[index][jindex] = 0;
        }
    }
}

unsigned short Board::Size()const
{
    return m_size;
}