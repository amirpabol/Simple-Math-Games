#ifndef SCORE_H
#define SCORE_H

class Score
{   
    private:
        int groupscore;
    
    public:
        Score()
        {   
            groupscore = 0;
        }
        Score(int S){   setScore(S);    }   
        ~Score(){};

        void setScore(int S)
        {
            groupscore = S;
        }
        int getScore()
        {
            return groupscore;
        }

};
#endif