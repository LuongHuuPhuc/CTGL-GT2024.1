#include <iostream>
#include <queue>           // Dùng trong BFS
#include <unordered_map>
#include <vector>
#include <algorithm>       // Hàm std::reverse

#define N 100 // Số ô của bàn cờ

/*
  BÀI TOÁN "SNAKE AND LADDER" (QUEUE)
  ---------------------------
  - Bàn cờ có 100 ô, đánh số 1..100
  - Có một số "cặp" (start -> end) thể hiện Thang hoặc Rắn:
       + Thang: start < end => đi từ start sẽ nhảy lên end.
       + Rắn  : start > end => đi từ start sẽ tụt xuống end.
  - Mỗi lượt, ta gieo xúc xắc (1..6) và di chuyển từ vị trí hiện tại. Nếu rơi 
    vào ô có rắn/thang, ta lập tức chuyển sang ô đích do rắn/thang quy định.
  - Mục tiêu: Tìm cách đến ô 100 với số lượt gieo xúc xắc ít nhất.
  ------------------------------------------------------
  - Sử dụng BFS trên bảng cờ:
    + Xem mỗi ô là một đỉnh (vertex).
    + Từ mỗi ô i, ta có thể gieo xúc xắc 6 giá trị (1..6), tạo ra các bước 
      di chuyển tới i+j (nếu i+j <= 100). Sau đó, nếu ô i+j là đầu của Rắn/Thang, 
      ta nhảy tới đích tương ứng.
  - Sử dụng hàng đợi (queue) để lưu trạng thái các ô cần xử lý.
  - Lưu mảng parent[] để theo dõi đường đi và mảng diceUsed[] để lưu giá trị xúc xắc.
  - Khi đến được ô 100, dừng BFS và truy hồi đường đi.
*/

/*
  Hàm BFS:
  - Thực hiện BFS từ ô 1 đến ô 100.
  - Trả về vector<int> gồm các giá trị xúc xắc đã gieo để đi từ 1 đến 100 (theo thứ tự).
  - Nếu không đến được 100, vector trả về rỗng.
*/
std::vector<int> BFS(int start, int target,
                     const std::unordered_map<int, int> &ladder,
                     const std::unordered_map<int, int> &snake) {
    // Hàng đợi lưu các ô cần xử lý cùng số lượt gieo để tới ô đó
    std::queue<std::pair<int, int>> q; // {vị trí ô, số lượt gieo}
    q.push({start, 0});

    // Mảng đánh dấu ô đã thăm
    std::vector<bool> visited(N + 1, false);
    visited[start] = true;

    // Mảng parent[u] để lưu "ô cha" của u
    std::vector<int> parent(N + 1, -1);
    // Mảng diceUsed[u] để lưu giá trị xúc xắc khi đi từ parent[u] đến u
    std::vector<int> diceUsed(N + 1, -1);

    // BFS
    while (!q.empty()) {
        auto [current, moves] = q.front();
        q.pop();

        // Nếu đã đến ô 100, ta có thể dừng BFS và truy hồi đường đi
        if (current == target) {
            std::vector<int> pathDice;
            int node = target;

            // Lần ngược từ ô 100 về ô 1 qua parent[], lưu diceUsed[]
            while (node != -1 && node != start) {
                pathDice.push_back(diceUsed[node]);
                node = parent[node];
            }

            // Đảo ngược lại vì ta vừa thu thập từ đích về nguồn
            std::reverse(pathDice.begin(), pathDice.end());

            return pathDice;
        }

        // Duyệt tất cả giá trị xúc xắc từ 1 đến 6
        for (int dice = 1; dice <= 6; ++dice) {
            int nextCell = current + dice;

            // Nếu ô tiếp theo vượt quá 100, bỏ qua
            if (nextCell > N) continue;

            // Nếu ô tiếp theo là đầu của Rắn hoặc Thang, nhảy đến đích
            if (ladder.find(nextCell) != ladder.end()) {
                nextCell = ladder.at(nextCell);
            } else if (snake.find(nextCell) != snake.end()) {
                nextCell = snake.at(nextCell);
            }

            // Nếu ô tiếp theo chưa được thăm, thêm vào hàng đợi
            if (!visited[nextCell]) {
                visited[nextCell] = true;
                parent[nextCell] = current;
                diceUsed[nextCell] = dice;
                q.push({nextCell, moves + 1});
            }
        }
    }

    // Nếu BFS xong mà không tìm thấy đường đến target, trả về mảng rỗng
    return {};
}

int main() {
    // Tạo bảng băm cho ladder, snake (Rắn và Thang)
    std::unordered_map<int, int> ladder;
    std::unordered_map<int, int> snake;

    // Nhập số lượng thang
    std::cout << "Nhập số lượng thang (ladder): ";
    int L;
    std::cin >> L;
    // Nhập từng cặp start -> end cho thang
    for (int i = 0; i < L; i++) {
        int start, end;
        std::cout << "Nhập cặp thang thứ " << i + 1 << " (start end): ";
        std::cin >> start >> end;
        ladder[start] = end;
    }

    // Nhập số lượng rắn
    std::cout << "Nhập số lượng rắn (snake): ";
    int S;
    std::cin >> S;
    // Nhập từng cặp start -> end cho rắn
    for (int i = 0; i < S; i++) {
        int start, end;
        std::cout << "Nhập cặp rắn thứ " << i + 1 << " (start end): ";
        std::cin >> start >> end;
        snake[start] = end;
    }

    // Tìm dãy xúc xắc dùng để đi từ 1 đến 100
    std::vector<int> result = BFS(1, 100, ladder, snake);

    // Nếu không có đường đi (result rỗng), in thông báo
    if (result.empty()) {
        std::cout << "Không thể đến đích!\n";
    } else {
        // In số lượt gieo:
        std::cout << "Số lượt gieo min: " << result.size() << "\n";
        // In các giá trị xúc xắc
        std::cout << "Các xúc xắc có thể gieo để được min (theo thứ tự): ";
        for (auto dice : result) {
            std::cout << dice << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
