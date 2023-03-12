#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int x;
    int y;
    int z;
    Node(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Node(){

    }
};

void bfs(bool*** visited, int*** dist, Node& start, Node& finish){

    queue<Node> queue;
    queue.push(start);
    while (!queue.empty()){
        Node temp = queue.front();
        queue.pop();

        if (visited[temp.x][temp.y][temp.z]){
            continue;
        } else{
            visited[temp.x][temp.y][temp.z] = true;
        }

        if (temp.x == finish.x && temp.y == finish.y && temp.z == finish.z){
            break;
        }

        if (temp.x - 1 >= 0 && !visited[temp.x - 1][temp.y][temp.z]){

            dist[temp.x - 1][temp.y][temp.z] = dist[temp.x][temp.y][temp.z] + 1;
            queue.push(Node(temp.x - 1, temp.y, temp.z));
        }
        if (temp.x + 1 < 100 && !visited[temp.x + 1][temp.y][temp.z]){

            dist[temp.x + 1][temp.y][temp.z] = dist[temp.x][temp.y][temp.z] + 1;
            queue.push(Node(temp.x + 1, temp.y, temp.z));
        }
        if (temp.y - 1 >= 0 && !visited[temp.x][temp.y - 1][temp.z]){

            dist[temp.x][temp.y - 1][temp.z] = dist[temp.x][temp.y][temp.z] + 1;
            queue.push(Node(temp.x, temp.y - 1, temp.z));
        }
        if (temp.y + 1 < 100 && !visited[temp.x][temp.y + 1][temp.z]){

            dist[temp.x][temp.y + 1][temp.z] = dist[temp.x][temp.y][temp.z] + 1;
            queue.push(Node(temp.x, temp.y + 1, temp.z));
        }
        if (temp.z - 1 >= 0 && !visited[temp.x][temp.y][temp.z - 1]){

            dist[temp.x][temp.y][temp.z - 1] = dist[temp.x][temp.y][temp.z] + 1;
            queue.push(Node(temp.x, temp.y, temp.z - 1));
        }
        if (temp.z + 1 < 100 && !visited[temp.x][temp.y][temp.z + 1]){

            dist[temp.x][temp.y][temp.z + 1] = dist[temp.x][temp.y][temp.z] + 1;
            queue.push(Node(temp.x, temp.y, temp.z + 1));
        }
    }
}

int main() {

    int houseCount, energy;
    cin >> houseCount >> energy;
    Node start = Node();
    Node finish = Node();
    cin >> start.x >> start.y >> start.z;
    cin >> finish.x >> finish.y >> finish.z;

    bool*** visited = new bool**[101];
    int*** dist = new int**[101];

    for (int i = 0; i < 101; ++i) {
        visited[i] = new bool*[101];
        dist[i] = new int*[101];

        for (int j = 0; j < 101; ++j) {
            dist[i][j] = new int[101];
            visited[i][j] = new bool[101];

            for (int k = 0; k < 101; ++k) {
                visited[i][j][k] = false;
                dist[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < houseCount; ++i) {
        int x,y,z,h;
        cin >> x >> y >> z >> h;
        for (int j = z; j < z + h; ++j) {
            visited[x][y][j] = true;
        }
    }

    if (finish.x == start.x && finish.y == start.y && finish.z == start.z){
        cout << 0;
        return 0;
    }

    bfs(visited, dist, start, finish);

    if (dist[finish.x][finish.y][finish.z] > energy || dist[finish.x][finish.y][finish.z] == 0){
        cout << -1;
    } else {
        cout << dist[finish.x][finish.y][finish.z];
    }

    return 0;
}
