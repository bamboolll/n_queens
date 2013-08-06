#include "solutionsearching.h"
#include "solutionsmodel.h"
#include "chessboard.h"
#include <cmath>
#include <QDebug>

SolutionsSearching::SolutionsSearching(int dimension)
    : m_dimension(dimension),
      m_algorithm(SolutionsSearching::Simple)
{
    this->chessBoard = new ChessBoard(dimension);
}

void SolutionsSearching::setDimension(int dimension)
{
  m_dimension = dimension;
}

void SolutionsSearching::reset()
{
    //reset board
    this->chessBoard = new ChessBoard(m_dimension);

}

ChessBoard* SolutionsSearching::findNextMove(){
    if(this->m_algorithm == SolutionsSearching::Simple)
        return findNextMove_Simple();
    else if(this->m_algorithm == SolutionsSearching::Steppest)
        return findNextMove_Steppest();
    else
        return this->chessBoard;//do nothing.
}

/**
 * The initial board must satisfy: no two Queens on the same row.
 * The first better solution in 56 avaiable next state.
 * @brief SolutionsSearching::findNextMove_Simple
 * @return
 *  Next board state using simple hillclimbing algorithm.
 */
ChessBoard* SolutionsSearching::findNextMove_Simple()
{
    int i, j;
    int current_score = this->calculateH(chessBoard);
    for (i = 0; i < m_dimension; ++i) {
        int tmp_col = getQueenAtRow(i);
        chessBoard->unsetQueen(i,tmp_col);
        for(j =0; j<m_dimension; ++j){
            chessBoard->setQueen(i,j);
            int tmp_score = this->calculateH(chessBoard);
            if(tmp_score<current_score)
                return chessBoard;
            chessBoard->unsetQueen(i,j);
        }
        chessBoard->unsetQueen(i,tmp_col);
    }
}

/**
 * @brief SolutionsSearching::getQueenAtRow
 * @param row
 * @return the col position of the first Queen on the row.
 */
int SolutionsSearching::getQueenAtRow(int row)
{
    int col = -1;
    for(col = 0; col < m_dimension; ++col){
        if(chessBoard->at(row,col)==ChessBoard::Queen)
            return col;
    }
    return col;
}

ChessBoard* SolutionsSearching::findNextMove_Steppest()
{
    int i, j;
    int best_row, best_col;
    best_row = best_col = -1;
    int best_score = this->calculateH(chessBoard);
    for (i = 0; i < m_dimension; ++i) {
        int tmp_col = getQueenAtRow(i);
        chessBoard->unsetQueen(i,tmp_col);
        for(j =0; j< m_dimension; ++j){
            chessBoard->setQueen(i,j);
            int tmp_score = this->calculateH(chessBoard);
            if(tmp_score<best_score){
                best_row = i;
                best_col = j;
                best_score = tmp_score;
            }
            chessBoard->unsetQueen(i,j);
        }
        chessBoard->unsetQueen(i,tmp_col);
    }
    if(best_row != -1){
        //find out a available move
        int tmp_col = getQueenAtRow(best_row);
        chessBoard->unsetQueen(best_row,tmp_col);
        chessBoard->setQueen(best_row,best_col);

    }else{
        //no move available.
        //do nothing
    }
    return chessBoard;
}


int SolutionsSearching::calculateH(ChessBoard* chessBoard){
    int score = 0;
    for (int i = 0; i < m_dimension; ++i) {
      for (int j = 0; j < m_dimension; ++j) {
        if (chessBoard->at(i, j) == ChessBoard::Queen) {
            //find the next queen position.
            for(int m =i+1; m < m_dimension; ++m){
                for( int n=j+1; n< m_dimension; ++n){
                    if(chessBoard->at(m,n)==ChessBoard::Queen){
                        //check if attackable.
                        if(checkAttackable(i,j,m,n))
                            score++;
                    }
                }
            }
          break;
        }
      }
    }
    return score;
}

bool SolutionsSearching::checkAttackable(int a,int b,int x,int y){
    if(a==x || b==y)
        return true;
    if(a==y && b==x)
        return true;

    return false;

}
