#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


const int row_dir[] = {-1,-1,0,1,1,1,0,-1};
const int col_dir[] = {0,1,1,1,0,-1,-1,-1};

class fireball
{
private:
    int row;
    int col;
    int mass;
    int speed;
    int direction;
public:
    fireball(int r, int c, int m, int s, int d)
    {
        this -> row = r;
        this -> col = c;
        this -> mass = m;
        this -> speed = s;
        this -> direction = d;
        cout << "\n" << r << "," <<c << "\n";
    }
    void move(map<pair<int, int>, vector<fireball *>*> *ball_map, const int n)
    {
        pair<int, int> pos;
        pos.first = this -> row;
        pos.second = this -> col;
        auto it = ball_map -> find(pos);
        auto balls = (*it).second;
        auto it_vec = balls -> begin();
        
        // 이전 흔적 지움
        while (it_vec != balls -> end() && *it_vec != this)
            ++it_vec;
        balls -> erase(it_vec);

        // 좌표 갱신
        this -> row = (this -> row + row_dir[this -> direction] * this -> speed) % n;
        this -> col = (this -> col + col_dir[this -> direction] * this -> speed) % n;

        // 새로 기록
        auto    it_newPos = ball_map -> find(pos);
        if (it_newPos != ball_map -> end())
        {
            (*it_newPos).second -> push_back(this);
        }
        else
        {
            vector<fireball *>  *newVec;
            newVec = new vector<fireball *>;
            ball_map -> insert({pos, newVec});
            newVec -> push_back(this);
        }
        // 이후에 맵에 중복 요소 merge, split 필요함
    }
    int get_row() const
    {
        return (this -> row);
    }
    int get_col() const
    {
        return (this -> col);
    }
    int get_mass() const
    {
        return (this -> mass);
    }
    int get_speed() const
    {
        return (this -> speed);
    }
    int get_direction() const
    {
        return (this -> direction);
    }
};

void    get_nmk(int *n, int *m, int *k)
{
    string  input;
    cin >> input;
    *n = stoi(input);
    cin >> input;
    *m = stoi(input);
    cin >> input;
    *k = stoi(input);
}

void    get_fireballs(const int M, map<pair<int, int>, vector<fireball *>*> *ball_map)
{
    string  input;
    int     r, c, m, s, d;
    for (int i = 0; i < M; ++i)
    {
        cin >> input;
        r = stoi(input) - 1;
        cin >> input;
        c = stoi(input) - 1;
        cin >> input;
        m = stoi(input);
        cin >> input;
        s = stoi(input);
        cin >> input;
        d = stoi(input);
        fireball *new_fireball = new fireball(r, c, m, s, d);

        pair<int, int> pos;
        pos.first = r;
        pos.second = c;

        auto    it = ball_map -> find(pos);
        if (it != ball_map -> end())
        {
            (*it).second -> push_back(new_fireball);
        }
        else
        {
            vector<fireball *>  *newVec;
            newVec = new vector<fireball *>;
            ball_map -> insert({pos, newVec});
            newVec -> push_back(new_fireball);
        }
    }
}

void    control_fireballs(map<pair<int, int>, vector<fireball *>*> *ball_map)
{
    auto    it_map = ball_map -> begin();

    while (it_map != ball_map -> end())
    {
        auto    vec_fb = (*it_map).second;
        auto    it_vec = vec_fb -> begin();

        int     row = (*it_map).first.first;
        int     col = (*it_map).first.second;
        int     mass = 0;
        int     speed = 0;
        int     count = 0;
        bool    odd = 1;
        bool    even = 1;

        if (vec_fb -> size() <= 1)
            return ;
        while (it_vec != vec_fb -> end())
        {
            count++;
            mass += (*it_vec) -> get_mass();
            speed += (*it_vec) -> get_speed();
            odd = odd ? (*it_vec) -> get_direction() % 2 == 1 : 0;
            even = even ? (*it_vec) -> get_direction() % 2 == 0 : 0;
            delete (*it_vec);
            ++it_vec;
        }
        vec_fb -> clear();
        mass = mass / 5;
        speed = speed / count;

        int flag = !(odd || even);
        if (mass)
        {
            for (int i = 0; i < 4; ++i)
            {
                vec_fb -> push_back(new fireball(row, col, mass, speed, i * 2 + flag));
            }
        }
        ++it_map;
    }
}

void    move_fireballs(map<pair<int, int>, vector<fireball *>*> *ball_map, const int n)
{
    auto it = ball_map -> begin();
    while (it != ball_map -> end())
    {
        vector<fireball *>  *fireballs;
        fireballs = (*it).second;
        for (int i = 0; i < fireballs -> size(); ++i)
        {
            (*fireballs)[i] -> move(ball_map, n);
        }
        ++it;
    }
}

int get_mass_sum(map<pair<int, int>, vector<fireball *>*> *ball_map)
{
    auto    it_map = ball_map -> begin();
    int     mass = 0;

    while (it_map != ball_map -> end())
    {
        auto    vec = (*it_map).second;
        auto    it_vec = (*vec).begin();
        while (it_vec != vec -> end())
        {
            mass += (*it_vec) -> get_mass();
            ++it_vec;
        }
        ++it_map;
    }
    return (mass);
}

int main(void)
{
    int                                     n, m, k;
    map<pair<int, int>, vector<fireball *>*> ball_map;
    get_nmk(&n, &m, &k);
    get_fireballs(m, &ball_map);
    for (int i = 0; i < k; ++i)
    {
        cout << "move\n";
        move_fireballs(&ball_map, n);
        control_fireballs(&ball_map);
    }
    cout << get_mass_sum(&ball_map);
    return (0);
}