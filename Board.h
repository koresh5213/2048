#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
    Board(unsigned short size);
    ~Board();

    unsigned short GetTile(unsigned short,unsigned short)const;
    void SetTile(unsigned short,unsigned short,unsigned short);

    void PrintBoard()const;
    void ClearBoard();

    unsigned short Size()const;

private:
    unsigned short ** m_board;
    unsigned short m_size;
};

#endif