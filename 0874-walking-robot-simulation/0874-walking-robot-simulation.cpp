class Solution
{
public:
    int distanceCalculate(int x1, int y1, int x2, int y2)
    {
        int x = x1 - x2; 
        int y = y1 - y2;
        int dist;

        dist = pow(x, 2) + pow(y, 2);
        
        return dist;
    }

    int changeDirection(int direction, int change) {

        direction += change;

        return direction < 0 ? 3 : direction % 4;
    }

    bool checkObstacle(vector<int>& pos, unordered_set<string>& obstacle_set) {
        
        if (obstacle_set.empty()) return false;

        string key = to_string(pos[0]) + "," + to_string(pos[1]);

        if (obstacle_set.find(key) != obstacle_set.end())
            return true;

        return false;
    }

    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {

        unordered_set<string> obstacle_set;
        
        int direction = 0;
        vector<int> pos = {0,0};
        int max_dist = 0;

        for (const vector<int> &obstacle : obstacles)
        {
            obstacle_set.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }



        for (int i = 0; i < commands.size(); i ++) {

            switch(commands[i]){

                case -1:
                    direction = changeDirection(direction, 1);
                    break;
                case -2:
                    direction = changeDirection(direction, -1);
                    break;
                default:
                    switch(direction){
                        case 0:
                            for (int j = 0; j < commands[i]; j ++) {

                                pos[1] ++;

                                if (checkObstacle(pos, obstacle_set)) {
                                    pos[1]--;
                                    break;
                                }

                            }
                            break;
                        case 1:
                            for (int j = 0; j < commands[i]; j ++) {

                                pos[0] ++;

                                if (checkObstacle(pos, obstacle_set)) {
                                    pos[0]--;
                                    break;
                                }

                            }
                            break;
                        case 2:
                            for (int j = 0; j < commands[i]; j ++) {

                                pos[1] --;

                                if (checkObstacle(pos, obstacle_set)) {
                                    pos[1]++;
                                    break;
                                }

                            }
                            break;
                        case 3:
                            for (int j = 0; j < commands[i]; j ++) {

                                pos[0] --;

                                if (checkObstacle(pos, obstacle_set)) {
                                    pos[0]++;
                                    break;
                                }

                            }
                            break;
                    }

                    max_dist = max(distanceCalculate(0,0,pos[0],pos[1]), max_dist);
                    
            }
        }

        return max_dist;
    }
};
