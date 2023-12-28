/*#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int map[65536][65536];
int visited[65536][65536];
int X1,Y1,X2,Y2;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(){
        queue<tuple<int,int,int> >q;
        //x,y,energy
        q.push(make_tuple(X1+32768,Y1+32768,1000));
        visited[Y1+32768][X1+32768]=1;

        while(!q.empty()){
                tuple<int,int,int>current=q.front();
                q.pop();

                if(get<0>(current)==X2-1&&get<1>(current)==Y2-1){
                        return visited[get<1>(current)][get<0>(current)]-1;
                }

                for(int i=0;i<4;i++){
                        int nx=dx[i]+get<0>(current);
                        int ny=dy[i]+get<1>(current);

                        if(nx>=0&&nx<65536&&ny>=0&&ny<65536&&map[ny][nx]==0&&!visited[ny][nx]&&get<2>(current)>0){
                                q.push(make_tuple(nx,ny,get<2>(current)-1));
                                visited[ny][nx]=visited[get<1>(current)][get<0>(current)]+1;
                        }
                        else if(nx>=0&&nx<65536&&ny>=0&&ny<65536&&map[ny][nx]==1&&!visited[ny][nx]&&get<2>(current)>0){
                                q.push(make_tuple(nx,ny,1000+(get<2>(current)-1)%50));
                                visited[ny][nx]=visited[get<1>(current)][get<0>(current)]+1;
                        }
                }
        }

        return -1;
}

int main(void){
        int t;
	cin>>t;
        int con;
        int conX1,conY1;
        while(t--){
                cin>>con;
                cin>>X1>>Y1;
                for(int i=0;i<con;i++){
                        cin>>conX1>>conY1;
                        map[conY1+32768][conX1+32768]=1;
                }
                cin>>X2>>Y2;
		X2+=32768;
		Y2+=32768;
                int sol=bfs();
		
		if(sol==-1){
			cout<<"sad"<<endl;
		}
		else{
			cout<<"happy"<<endl;
		}
	}
}*/

#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int** map;
int** visited;
int X1, Y1, X2, Y2;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs() {
    queue<tuple<int, int, int>> q;
    // x, y, energy
    q.push(make_tuple(X1 + 32768, Y1 + 32768, 1000));
    visited[Y1 + 32768][X1 + 32768] = 1;

    while (!q.empty()) {
        tuple<int, int, int> current = q.front();
        q.pop();

        if (get<0>(current) == X2 - 1 && get<1>(current) == Y2 - 1) {
            return visited[get<1>(current)][get<0>(current)] - 1;
        }

        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + get<0>(current);
            int ny = dy[i] + get<1>(current);

            if (nx >= 0 && nx < 65536 && ny >= 0 && ny < 65536 && map[ny][nx] == 0 && !visited[ny][nx] && get<2>(current) > 0) {
                q.push(make_tuple(nx, ny, get<2>(current) - 1));
                visited[ny][nx] = visited[get<1>(current)][get<0>(current)] + 1;
            } else if (nx >= 0 && nx < 65536 && ny >= 0 && ny < 65536 && map[ny][nx] == 1 && !visited[ny][nx] && get<2>(current) > 0) {
                q.push(make_tuple(nx, ny, 1000 + (get<2>(current) - 1) % 50));
                visited[ny][nx] = visited[get<1>(current)][get<0>(current)] + 1;
            }
        }
    }

    return -1;
}

int main(void) {
    int t;
    cin >> t;
    int con;
    int conX1, conY1;

    map = new int*[65536];
    visited = new int*[65536];
    for (int i = 0; i < 65536; ++i) {
        map[i] = new int[65536];
        visited[i] = new int[65536];
    }

    while (t--) {
        cin >> con;
        cin >> X1 >> Y1;

        for (int i = 0; i < con; i++) {
            cin >> conX1 >> conY1;
            map[conY1 + 32768][conX1 + 32768] = 1;
        }

        cin >> X2 >> Y2;
        X2 += 32768;
        Y2 += 32768;

        int sol = bfs();

        if (sol == -1) {
            cout << "sad" << endl;
        } else {
            cout << "happy" << endl;
        }
    }

    // Free dynamically allocated memory
    for (int i = 0; i < 65536; ++i) {
        delete[] map[i];
        delete[] visited[i];
    }
    delete[] map;
    delete[] visited;

    return 0;
}

