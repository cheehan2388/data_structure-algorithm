#include <iostream>
#include <string>

// 定義一個裝備的結構（假設裝備資料很大，包含名字、數值、外觀描述等）
struct Weapon {
    std::string name;
    int attackPower;
};

// 定義角色的結構
struct Player {
    std::string name;
    int hp;
};

struct monster{
    std::string name;
    int hp;

};
// 【體驗點 1】：使用指標來「真正修改」外部資料
// 傳入 Player* 代表我們拿到了「玩家置物櫃的地址」
void drinkPotion(Player* playerObj) {
    std::cout << "\n[系統] 玩家喝下治癒藥水！" << std::endl;
    
    // 順著地址找到那個玩家櫃子，把裡面的 HP 加上 50
    playerObj->hp += 50; 
    // 備註：playerObj->hp 是 (*playerObj).hp 的簡寫，意思是順著地址去找裡面的成員
}

// 【體驗點 2】：使用指標來「避免複製大檔案」
// 傳入 Weapon* 代表我們只拿一張「寫著武器地址的便條紙」
void putInInventory(Weapon* weaponObj) {
    std::cout << "[背包] 成功將裝備放進背包！" << std::endl;
    // 這裡我們只拿到了地址，不需要在函式內複製整把武器的資料，超級省記憶體
    std::cout << "[背包] 目前檢查背包內武器為: " << weaponObj->name << " (攻擊力: " << weaponObj->attackPower << ")" << std::endl;
}

void attack(monster* monsterObj,Weapon* weaponObj){
    std::cout << "使用" << weaponObj->name << "攻擊怪獸" << monsterObj->name << std::endl  ;
    monsterObj->hp -= weaponObj ->attackPower ;
    

} 

int main() {
    // 1. 在 main 創造真正的玩家與武器（佔用真正的置物櫃）
    Player player1 = {"勇者小明", 100};
    Weapon heavySword = {"王者之劍", 9999}; // 假設這把武器有很多複雜資料
    monster monster1 = {"魔王", 1000} ;

    std::cout << "--- 遊戲開始 ---" << std::endl;
    std::cout << player1.name << " 目前的初始血量為: " << player1.hp << std::endl;

    // 2. 呼叫喝藥水函式。
    // 注意：這裡使用 &player1，意思是「把 player1 的記憶體地址（號碼牌）傳過去」
    drinkPotion(&player1);

    // 3. 檢查 main 裡面的 player1 是不是真的被改到了？
    std::cout << "[檢查] 回到主程式，" << player1.name << " 现在的血量變成: " << player1.hp << std::endl;
    std::cout << "（你看！不用指標的話，函式裡改的血量一結束就消失了，只有用指標才能真正改到 main 裡的東西！）" << std::endl;
    attack(&monster1,&heavySword);
    std::cout << monster1.name << "血量變成" << monster1.hp << std::endl;
    std::cout << "\n----------------" << std::endl;

    // 4. 呼叫背包函式。
    // 同理，傳送武器的地址 &heavySword 過去，不複製整把劍
    putInInventory(&heavySword);

    return 0;
}