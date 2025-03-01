#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
char map[101][101];

class Monster;
class Boss;
class ItemBox;
class Player;
class GameManager;
class AccStatus;

// =====================================================
// 클래스 선언부
// =====================================================


// ItemBox
class ItemBox {
public:
    ItemBox(char type, int x, int y, int n); // Weapon, Armor type
    ItemBox(char type, int x, int y, string acc_type); // Acc type 
    pair<int, int> getPosition();
    char getType() const;
    int getN() const;
    string getAccType() const;
private:
    char type;
    int x;
    int y;
    int n;
    string acc_type;
};

class Player {
public:
    static Player& getInstance();

    void initPos(int x, int y);
    void takeDamage(int damage);
    pair<int, int> getPosition();
    bool getReasonKilled();
    int getLevel();
    int getCurHp();
    int getMaxHp();
    int getAd();
    int getWeaponD();
    int getDef();
    int getArmorD();
    int getExp();
    vector<string> getAcc();
    bool OnSpike();

    void move(char direction);
    void levelUp();
    void gainExp(int exp);
    void openBox(const ItemBox* itembox);
    void die();

private:
    Player();
    Player(const Player& ref);
    Player& operator=(const Player& ref);
    ~Player();

    int x, y;
    int level;
    int max_hp;
    int cur_hp;
    int attack_damage;
    int defense;
    int exp;
    int weapon;
    int armor;
    int spikex;
    int spikey;
    bool co_passive;
    bool hu_passive;
    bool killed_by_monster;
    bool killed_by_spike;
    vector<string> acc;
};

class GameManager {
public:
    static GameManager& getInstance();

    void printMap();
    void spawnMonster(int x, int y, string name, int hp, int attack_damage, int defense, int exp);
    void spawnBoss(int x, int y, string name, int hp, int attack_damage, int defense, int exp);
    void spawnItemBoxWA(char type, int x, int y, int n);
    void spawnItemBoxAcc(char type, int x, int y, string s);
    Monster* currentMonster(int monster_x, int monster_y);
    ItemBox* currentItemBox();
    void updateInitPos(int x, int y);
    pair<int, int> getInitPos();
    void bossKilled();
    void playerDiedReason();
    void playerDied();
    void monsterKilled(Monster* monster);
    void monsterKilledPlayer(Monster* monster);
    void noMoreInput();
    void turnUp();
    vector<Monster*> getMonstersArray();

private:
    GameManager();
    GameManager(const GameManager& ref);
    GameManager& operator=(const GameManager& ref);
    ~GameManager();

    int passed_turns;
    int initx;
    int inity;
    string monster_name;
    vector<Monster*> monsters;
    vector<ItemBox*> item_boxes;
};

//몬스터
class Monster {
public:
    Monster();
    Monster(int x, int y, string name, int max_hp, int attack_damage, int defense, int exp);
    pair<int, int> getPosition();
    int getHp();
    string getName();
    void takeDamage(int damage);
    int attack();
    int getExp();
    void updateHp();
    int getDefense();
    virtual void die();

protected:
    int x;
    int y;
    string name;
    int max_hp;
    int cur_hp;
    int attack_damage;
    int defense;
    int exp;
};

//보스
class Boss : public Monster {
public:
    Boss(int x, int y, string name, int max_hp, int attack_damage, int defense, int exp);
    void die() override;
};

class AccStatus {
public:
    static AccStatus& getInstance();

    void AccStatusCheck();
    void AccStatusInit();
    void usedRE();
    bool getHRStatus();
    bool getREStatus();
    bool getCOStatus();
    bool getEXStatus();
    bool getDXStatus();
    bool getHUStatus();

private:
    AccStatus();
    AccStatus(const AccStatus& ref);
    AccStatus& operator=(const AccStatus& ref);
    ~AccStatus();

    bool hr;
    bool re;
    bool co;
    bool ex;
    bool dx;
    bool hu;
    bool cu;
};

// =====================================================
// 멤버 함수 정의 
// =====================================================

// --------------------- ItemBox ---------------------
ItemBox::ItemBox(char type, int x, int y, int n)
    : type(type), x(x), y(y), n(n) {}
ItemBox::ItemBox(char type, int x, int y, string acc_type)
    : type(type), x(x), y(y), acc_type(acc_type) {}
pair<int, int> ItemBox::getPosition() {
    return make_pair(x, y);
}
char ItemBox::getType() const {
    return type;
}
int ItemBox::getN() const {
    return n;
}
string ItemBox::getAccType() const {
    return acc_type;
}

// --------------------- Player ---------------------
Player& Player::getInstance() {
    static Player player;
    return player;
}
Player::Player() : level(1), max_hp(20), cur_hp(20), attack_damage(2), defense(2), exp(0), weapon(0), armor(0),
spikex(-1), spikey(-1), co_passive(false), killed_by_monster(false), killed_by_spike(false), acc(4, "") {}
Player::~Player() {}
Player::Player(const Player& ref) {}
Player& Player::operator=(const Player& ref) { return *this; }
void Player::initPos(int x, int y) {
    this->x = x;
    this->y = y;
}
void Player::takeDamage(int damage) {
    cur_hp -= max(1, damage);
    if (cur_hp < 0) cur_hp = 0;
}
pair<int, int> Player::getPosition() {
    return make_pair(this->x, this->y);
}
bool Player::getReasonKilled() {
    return killed_by_monster;
}
int Player::getLevel() {
    return level;
}
int Player::getCurHp() {
    return cur_hp;
}
int Player::getMaxHp() {
    return max_hp;
}
int Player::getAd() {
    return attack_damage;
}
int Player::getWeaponD() {
    return weapon;
}
int Player::getDef() {
    return defense;
}
int Player::getArmorD() {
    return armor;
}
int Player::getExp() {
    return exp;
}
vector<string> Player::getAcc() {
    return acc;
}
bool Player::OnSpike() {
    return (x == spikex && y == spikey);
}

void Player::move(char Direction)
{
    int current_x = Player::getPosition().first;
    int current_y = Player::getPosition().second;
    int next_x = current_x;
    int next_y = current_y;
    if (Direction == 'R') next_y++;
    else if (Direction == 'L') next_y--;
    else if (Direction == 'U') next_x--;
    else if (Direction == 'D') next_x++;
    if (next_x >= 1 && next_y >= 1 && next_x <= n && next_y <= m && map[next_x][next_y] != '#')
    {
        if (map[next_x][next_y] == '.')
        {
            this->x = next_x;
            this->y = next_y;
            if (current_x == spikex && current_y == spikey) map[current_x][current_y] = '^';
            else map[current_x][current_y] = '.';
            map[next_x][next_y] = '@';
        }
        else if (map[next_x][next_y] == '&')
        {
            Monster* monster = GameManager::getInstance().currentMonster(next_x, next_y);
           
            if (AccStatus::getInstance().getCOStatus()) {
             
                co_passive = true;
            }

            while (this->cur_hp > 0 && monster->getHp() > 0) {

               

                if (co_passive && AccStatus::getInstance().getDXStatus()) {

                    

                    monster->takeDamage((this->attack_damage + this->weapon) * 3);
                    co_passive = false;
                }

                else if (co_passive) {
                    monster->takeDamage((this->attack_damage + this->weapon) * 2);
                    co_passive = false;
                }
                else {
                    monster->takeDamage((this->attack_damage + this->weapon));
                }
                if (monster->getHp() <= 0)
                {
                   
                    break;
                }
                takeDamage(monster->attack() - (defense + armor));

             

            }
            if (cur_hp <= 0) {
                if (current_x == spikex && current_y == spikey) map[current_x][current_y] = '^';
                else map[current_x][current_y] = '.';
               
                GameManager::getInstance().monsterKilledPlayer(monster);
                killed_by_monster = true;
                die();
            }
            else {
                this->x = next_x;
                this->y = next_y;
                if (current_x == spikex && current_y == spikey) map[current_x][current_y] = '^';
                else map[current_x][current_y] = '.';
                map[next_x][next_y] = '@';
                
                bool hr = AccStatus::getInstance().getHRStatus();
                bool ex = AccStatus::getInstance().getEXStatus();
                if (hr)
                {
                    cur_hp = cur_hp + 3 >= max_hp ? max_hp : cur_hp + 3;
                }

                if (ex)
                {
                   

                    gainExp((int)(monster->getExp() * 1.2));
                }
                else gainExp(monster->getExp());

             

                monster->die();
                if (AccStatus::getInstance().getCOStatus()) co_passive = true;
            }

        }
        else if (map[next_x][next_y] == 'M')
        {
            Monster* monster = GameManager::getInstance().currentMonster(next_x, next_y);
            
            if (AccStatus::getInstance().getCOStatus()) {
               
                co_passive = true;
            }

            if (AccStatus::getInstance().getHUStatus()) {

                hu_passive = true;
                cur_hp = max_hp;
            }

            while (this->cur_hp > 0 && monster->getHp() > 0) {

             

                if (co_passive && AccStatus::getInstance().getDXStatus()) {

                   

                    monster->takeDamage((this->attack_damage + this->weapon) * 3);
                    co_passive = false;
                }

                else if (co_passive) {
                    monster->takeDamage((this->attack_damage + this->weapon) * 2);
                    co_passive = false;
                }
                else {
                    monster->takeDamage((this->attack_damage + this->weapon));
                }
                if (monster->getHp() <= 0)
                {
                   
                    break;
                }
                if (hu_passive)
                {
                    cur_hp += max(1, monster->attack() - (defense + armor));
                    hu_passive = false;
                }
               
                takeDamage(monster->attack() - (defense + armor));

               

            }
            if (cur_hp <= 0) {
                if (current_x == spikex && current_y == spikey) map[current_x][current_y] = '^';
                else map[current_x][current_y] = '.';
              

                GameManager::getInstance().monsterKilledPlayer(monster);
                killed_by_monster = true;
                die();
            }
            else {
                this->x = next_x;
                this->y = next_y;
                if (current_x == spikex && current_y == spikey) map[current_x][current_y] = '^';
                else map[current_x][current_y] = '.';
                map[next_x][next_y] = '@';
             

                bool hr = AccStatus::getInstance().getHRStatus();
                bool ex = AccStatus::getInstance().getEXStatus();
                if (hr)
                {
                   

                    cur_hp = cur_hp + 3 >= max_hp ? max_hp : cur_hp + 3;
                }

                if (ex)
                {
                  

                    gainExp((int)(monster->getExp() * 1.2));
                }
                else gainExp(monster->getExp());

             

                monster->die();
                if (AccStatus::getInstance().getCOStatus()) co_passive = true;
                if (AccStatus::getInstance().getHUStatus()) hu_passive = true;
            }
        }
        else if (map[next_x][next_y] == 'B')
        {
          
            this->x = next_x;
            this->y = next_y;
            if (current_x == spikex && current_y == spikey) map[current_x][current_y] = '^';
            else map[current_x][current_y] = '.';
            map[next_x][next_y] = '@';
            ItemBox* itembox = GameManager::getInstance().currentItemBox();
            this->openBox(itembox);
        }
        else if (map[next_x][next_y] == '^')
        {
           

            this->x = next_x;
            this->y = next_y;
            if (current_x == spikex && current_y == spikey) map[current_x][current_y] = '^';
            else map[current_x][current_y] = '.';
            map[next_x][next_y] = '@';
            spikex = next_x;
            spikey = next_y;

            if (AccStatus::getInstance().getDXStatus()) this->takeDamage(1);
            else this->takeDamage(5);

            if (cur_hp <= 0)
            {
                map[next_x][next_y] = '^';
                die();
            }
        }


    }
    else
    {
        this->x = current_x;
        this->y = current_y;
        if (OnSpike()) {
            if (AccStatus::getInstance().getDXStatus()) this->takeDamage(1);
            else this->takeDamage(5);
            if (cur_hp <= 0)
            {
                map[current_x][current_y] = '^';
                die();
            }
        }
    }

}
void Player::levelUp() {
    exp = 0;
    level += 1;
    max_hp += 5;
    cur_hp = max_hp;
    attack_damage += 2;
    defense += 2;
}
void Player::gainExp(int exp) {
    this->exp += exp;
    if (this->exp >= level * 5) {
        levelUp();
       
    }
}

void Player::openBox(const ItemBox* itembox) {
    char type = itembox->getType();

   

    if (type == 'W') {

      
        this->weapon = itembox->getN();
    }
    else if (type == 'A') {

       

        this->armor = itembox->getN();
    }
    else {

      
        bool have = false;
        string acc_type = itembox->getAccType();

    

        for (int i = 0; i < 4; i++) {
            if (acc[i] == acc_type) {

              

                have = true;
                break;
            }
        }
        if (!have) {
            for (int i = 0; i < 4; i++) {
                if (acc[i] == "") {

                 

                    acc[i] = acc_type;
                    AccStatus::getInstance().AccStatusInit();
                    AccStatus::getInstance().AccStatusCheck();
                    break;
                }
            }
        }
    }
}
void Player::die() {

  

    if (AccStatus::getInstance().getREStatus()) {

       
        AccStatus::getInstance().usedRE();
        pair<int, int> initPos = GameManager::getInstance().getInitPos();


        this->x = initPos.first;
        this->y = initPos.second;
        this->cur_hp = max_hp;
        map[x][y] = '@';
      

        for (int i = 0; i < 4; i++) {
            if (acc[i] == "RE") acc[i] = "";
        }
        for (auto it : GameManager::getInstance().getMonstersArray()) {
            it->updateHp();
        }
        killed_by_monster = false;
        killed_by_spike = false;
    }
    else {
        GameManager::getInstance().playerDied();
    }
}

// --------------------- GameManager ---------------------
GameManager& GameManager::getInstance() {
    static GameManager gameManager;
    return gameManager;
}
GameManager::GameManager() : passed_turns(0), initx(0), inity(0) {}
GameManager::~GameManager() {}
GameManager::GameManager(const GameManager& ref) {}
GameManager& GameManager::operator=(const GameManager& ref) { return *this; }
void GameManager::printMap() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
}
void GameManager::spawnMonster(int x, int y, string name, int hp, int attack_damage, int defense, int exp) {
    Monster* monster = new Monster(x, y, name, hp, attack_damage, defense, exp);
    monsters.push_back(monster);


}
void GameManager::spawnBoss(int x, int y, string name, int hp, int attack_damage, int defense, int exp) {
    Boss* boss = new Boss(x, y, name, hp, attack_damage, defense, exp);
    monsters.push_back(boss);
}
void GameManager::spawnItemBoxWA(char type, int x, int y, int n) {
    ItemBox* itembox = new ItemBox(type, x, y, n);
    item_boxes.push_back(itembox);
}
void GameManager::spawnItemBoxAcc(char type, int x, int y, string s) {
    ItemBox* itembox = new ItemBox(type, x, y, s);
    item_boxes.push_back(itembox);
}
void GameManager::turnUp()
{
    passed_turns++;
}
Monster* GameManager::currentMonster(int monster_x, int monster_y) {
    pair<int, int> monster_position = { monster_x,monster_y };
    for (int i = 0; i < monsters.size(); i++) {
        if (monsters[i] && monsters[i]->getPosition() == monster_position) {
            return monsters[i];
        }
    }
    return nullptr;
}
ItemBox* GameManager::currentItemBox() {
    pair<int, int> player_position = Player::getInstance().getPosition();
    for (int i = 0; i < item_boxes.size(); i++) {
        if (item_boxes[i] && item_boxes[i]->getPosition() == player_position) {
            return item_boxes[i];
        }
    }
    return nullptr;
}
void GameManager::updateInitPos(int x, int y) {
    this->initx = x;
    this->inity = y;
}
pair<int, int> GameManager::getInitPos() {
    return make_pair(initx, inity);
}
void GameManager::bossKilled() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << "Passed Turns : " << passed_turns << "\n";
    cout << "LV : " << Player::getInstance().getLevel() << "\n";
    cout << "HP : " << Player::getInstance().getCurHp() << "/" << Player::getInstance().getMaxHp() << "\n";
    cout << "ATT : " << Player::getInstance().getAd() << "+" << Player::getInstance().getWeaponD() << "\n";
    cout << "DEF : " << Player::getInstance().getDef() << "+" << Player::getInstance().getArmorD() << "\n";
    cout << "EXP : " << Player::getInstance().getExp() << "/" << Player::getInstance().getLevel() * 5 << "\n";
    cout << "YOU WIN!" << "\n";
    exit(0);
}
void GameManager::playerDiedReason() {
    if (Player::getInstance().getReasonKilled()) {
        cout << "YOU HAVE BEEN KILLED BY " + monster_name + ".." << "\n";
    }
    else {
        cout << "YOU HAVE BEEN KILLED BY SPIKE TRAP.." << "\n";
    }
}
void GameManager::playerDied() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << "Passed Turns : " << passed_turns << "\n";
    cout << "LV : " << Player::getInstance().getLevel() << "\n";
    cout << "HP : " << Player::getInstance().getCurHp() << "/" << Player::getInstance().getMaxHp() << "\n";
    cout << "ATT : " << Player::getInstance().getAd() << "+" << Player::getInstance().getWeaponD() << "\n";
    cout << "DEF : " << Player::getInstance().getDef() << "+" << Player::getInstance().getArmorD() << "\n";
    cout << "EXP : " << Player::getInstance().getExp() << "/" << Player::getInstance().getLevel() * 5 << "\n";
    playerDiedReason();
    exit(0);
}
void GameManager::monsterKilled(Monster* monster) {
    auto it = find(monsters.begin(), monsters.end(), monster);
    if (it != monsters.end()) {
        monsters.erase(it);
        delete monster;
    }
}
void GameManager::monsterKilledPlayer(Monster* monster) {
    monster_name = monster->getName();
}
void GameManager::noMoreInput() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << "Passed Turns : " << passed_turns << "\n";
    cout << "LV : " << Player::getInstance().getLevel() << "\n";
    cout << "HP : " << Player::getInstance().getCurHp() << "/" << Player::getInstance().getMaxHp() << "\n";
    cout << "ATT : " << Player::getInstance().getAd() << "+" << Player::getInstance().getWeaponD() << "\n";
    cout << "DEF : " << Player::getInstance().getDef() << "+" << Player::getInstance().getArmorD() << "\n";
    cout << "EXP : " << Player::getInstance().getExp() << "/" << Player::getInstance().getLevel() * 5 << "\n";
    cout << "Press any key to continue." << "\n";
    exit(0);
}
vector<Monster*> GameManager::getMonstersArray() {
    return monsters;
}

// --------------------- Monster ---------------------
Monster::Monster() {}
Monster::Monster(int x, int y, string name, int max_hp, int attack_damage, int defense, int exp)
    : x(x), y(y), name(name), max_hp(max_hp), cur_hp(max_hp), attack_damage(attack_damage), defense(defense), exp(exp) {}
pair<int, int> Monster::getPosition() {
    return make_pair(x, y);
}
int Monster::getHp() {
    return cur_hp;
}
string Monster::getName() {
    return name;
}
void Monster::takeDamage(int damage) {
    cur_hp -= max(1, damage - defense);

}
int Monster::attack() {
    return attack_damage;
}
int Monster::getExp() {
    return this->exp;
}
void Monster::updateHp() {
    cur_hp = max_hp;
}
int Monster::getDefense()
{
    return defense;
}
void Monster::die() {

    
    GameManager::getInstance().monsterKilled(this);

}

// --------------------- Boss ---------------------
Boss::Boss(int x, int y, string name, int max_hp, int attack_damage, int defense, int exp)
    : Monster(x, y, name, max_hp, attack_damage, defense, exp) {}
void Boss::die() {

  

    GameManager::getInstance().bossKilled();
}

// --------------------- AccStatus ---------------------
AccStatus& AccStatus::getInstance() {
    static AccStatus acc_status;
    return acc_status;
}
AccStatus::AccStatus() : hr(false), re(false), co(false), ex(false), dx(false), hu(false), cu(false) {}
AccStatus::~AccStatus() {}
AccStatus::AccStatus(const AccStatus& ref) {}
AccStatus& AccStatus::operator=(const AccStatus& ref) { return *this; }
void AccStatus::AccStatusCheck() {

    vector<string> acc = Player::getInstance().getAcc();

    for (int i = 0; i < 4; i++) {

        if (acc[i] == "HR") hr = true;
        else if (acc[i] == "RE") re = true;
        else if (acc[i] == "CO") co = true;
        else if (acc[i] == "EX") ex = true;
        else if (acc[i] == "DX") dx = true;
        else if (acc[i] == "HU") hu = true;
        else if (acc[i] == "CU") cu = true;
    }

}
void AccStatus::AccStatusInit() {
    hr = false;
    re = false;
    co = false;
    ex = false;
    dx = false;
    hu = false;
    cu = false;
}
void AccStatus::usedRE() {
    re = false;
}
bool AccStatus::getHRStatus() {
    return hr;
}
bool AccStatus::getREStatus() {
    return re;
}
bool AccStatus::getCOStatus() {
    return co;
}
bool AccStatus::getEXStatus() {
    return ex;
}
bool AccStatus::getDXStatus() {
    return dx;
}
bool AccStatus::getHUStatus() {
    return hu;
}

// =====================================================
// main 함수
// =====================================================
int main() {
    cin >> n >> m;

    int monster_cnt = 0;
    int itembox_cnt = 0;
    int boss_x = 0, boss_y = 0;
    GameManager& gameManager = GameManager::getInstance();
    Player& player = Player::getInstance();

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if (map[i][j] == '&')
                monster_cnt++;
            else if (map[i][j] == 'B')
                itembox_cnt++;
            else if (map[i][j] == '@') {
                player.initPos(i, j);
                gameManager.updateInitPos(i, j);
            }
            else if (map[i][j] == 'M') {
                boss_x = i;
                boss_y = j;
                monster_cnt++;
            }
        }

    string moveCommand;
    cin >> moveCommand;

    /*
    R C S W A H E(1 ≤ R ≤ N, 1 ≤ C ≤ M, 1 ≤ | S | ≤ 10, 1 ≤ W, A, H, E ≤ 20)
        위에서부터 R번째 줄, 왼쪽에서부터 C번째 열에 있는 몬스터에 대한 정보이다.이 칸에는 몬스터가 있음이 보장된다.
        S는 몬스터의 이름으로, 알파벳 대소문자로만 이루어진 1글자 이상, 10글자 이하의 문자열이다.
        보스 몬스터를 포함해 모든 몬스터의 이름은 서로 다르다.
        W는 몬스터의 공격력 값이다.
        A는 몬스터의 방어력 값이다.
        H는 몬스터의 최대 체력이다.
        E는 몬스터를 쓰러뜨렸을 때 얻을 수 있는 경험치이다.
        모든 몬스터에 대한 정보는 정확히 한 번씩 주어진다.
    */

    for (int i = 0; i < monster_cnt; i++) {
        int R, C, W, A, H, E;
        string S;
        cin >> R >> C >> S >> W >> A >> H >> E;
        if (R == boss_x && C == boss_y)
            gameManager.spawnBoss(R, C, S, H, W, A, E);
        else
            gameManager.spawnMonster(R, C, S, H, W, A, E);
    }

    /*
    R C T <S>(1 <= R <= N, 1 <= C <= M, T ∈{ 'W', ‘A’, ‘O’ })
        위에서부터 R번째 줄, 왼쪽에서부터 C번째 열에 있는 아이템 상자에 대한 정보이다.이 칸에는 아이템 상자가 있음이 보장된다.
        T = 'W', 'A'일 경우
        <S> = N(1 ≤ N ≤ 10)
        T = 'W'일 경우 공격력이 N인 무기를, T = 'A'일 경우 방어력이 N인 방어구를 의미한다.
        T = 'O'일 경우
        <S> ∈{ "HR", "RE", "CO", "EX", "DX", "HU", "CU" }
        각 효과를 가진 장신구임을 의미한다.자세한 내용은 본문을 참조한다.
        모든 아이템 상자에 대한 정보가 정확히 한 번씩 주어진다.
    */

    for (int i = 0; i < itembox_cnt; i++) {
        int R, C;
        char T;
        cin >> R >> C >> T;
        if (T == 'W' || T == 'A') {
            int S;
            cin >> S;
            gameManager.spawnItemBoxWA(T, R, C, S);
        }
        else {
            string S;
            cin >> S;
            gameManager.spawnItemBoxAcc(T, R, C, S);
        }
    }

    for (int i = 0; i < moveCommand.length(); i++) {
        GameManager::getInstance().turnUp();
        Player::getInstance().move(moveCommand[i]);
    }
    GameManager::getInstance().noMoreInput();
    return 0;
}