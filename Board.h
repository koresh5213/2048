#ifndef BOARD_H
#define BOARD_H


// Class board- nXn board filled with 'unsigned long'
class Board
{
public:
    Board(unsigned short size);
    Board(const Board&);
    ~Board();

    unsigned long GetTile(unsigned short,unsigned short)const;
    void SetTile(unsigned short,unsigned short,unsigned long);

    void PrintBoard()const;
    void ClearBoard();

    unsigned short Size()const;

private:
    unsigned short NumOfDigits(unsigned long n)const;

    unsigned long ** m_board;
    unsigned short m_size;
};

#endif