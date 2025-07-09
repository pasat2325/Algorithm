#include <iostream>
using namespace std;

char map[100][100];
bool visited[100][100];
bool acquired_doc[100][100];
int key_status = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int w, h;
int ans = 0;

void key_update(char key) {
	int key_to_i = key - 'a';
	key_status |= (1 << key_to_i);
	return;
}

bool has_key(char door) {
	int door_to_i = door - 'A';
	return key_status & (1 << door_to_i);
}

bool is_key_updated(int prior, int after) {
	return prior != after;
}

void search_key(int x, int y) {
	if (islower(map[x][y])) {
		key_update(map[x][y]);
	}
	if (map[x][y] == '$' && !acquired_doc[x][y]) {
		acquired_doc[x][y] = true;
		ans++;
	}

	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_y >= 0 && next_x < h && next_y < w && !visited[next_x][next_y] && map[next_x][next_y] != '*') {
			if (map[next_x][next_y] >= 65 && map[next_x][next_y] <= 90)
				if (!has_key(map[next_x][next_y])) continue;
			search_key(next_x, next_y);
		}
	}
}
int main() {
	int tc;
	cin >> tc;
	for (int test = 0; test < tc; test++) {
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		string keys;
		cin >> keys;
		key_status = 0;

		if (keys != "0") for (int i = 0; i < keys.length(); i++) key_update(keys[i]);

		for (int i = 0; i < h; i++) {
			fill_n(acquired_doc[i], w, 0);
		}

		int prior_key;
		ans = 0;
		do {
			prior_key = key_status;
			for (int i = 0; i < h; i++) {
				fill_n(visited[i], w, 0);
			}
			for (int i = 0; i < h; i++) {
				int x = i;
				int y = 0;
				if (map[x][y] == '.' || (map[x][y] >=97 && map[x][y] <= 122) || map[x][y] == '$') search_key(x, y);
				if (map[x][y] >= 65 && map[x][y] <= 90) if (has_key(map[x][y])) search_key(x, y);
			}
			for (int i = 0; i < h; i++) {
				int x = i;
				int y = w - 1;
				if (map[x][y] == '.' || (map[x][y] >= 97 && map[x][y] <= 122) || map[x][y] == '$') search_key(x, y);
				if (map[x][y] >= 65 && map[x][y] <= 90) if (has_key(map[x][y])) search_key(x, y);
			}
			for (int i = 0; i < w; i++) {
				int x = 0;
				int y = i;
				if (map[x][y] == '.' || (map[x][y] >= 97 && map[x][y] <= 122) || map[x][y] == '$') search_key(x, y);
				if (map[x][y] >= 65 && map[x][y] <= 90) if (has_key(map[x][y])) search_key(x, y);
			}
			for (int i = 0; i < w; i++) {
				int x = h - 1;
				int y = i;
				if (map[x][y] == '.' || (map[x][y] >= 97 && map[x][y] <= 122) || map[x][y] == '$') search_key(x, y);
				if (map[x][y] >= 65 && map[x][y] <= 90) if (has_key(map[x][y])) search_key(x, y);
			}
		} while (is_key_updated(prior_key, key_status));
		cout << ans << "\n";
	}
}