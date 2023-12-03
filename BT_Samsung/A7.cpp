#include <iostream>
#include <vector>

using namespace std;

// Directions for exploring the neighbors of a pixel
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

// Check if a pixel is valid (lies within the image) and is of the same color
bool isValid(vector<vector<int>>& image, int x, int y, int oldColor) {
    return (x >= 0 && x < image.size() && y >= 0 && y < image[0].size() && image[x][y] == oldColor);
}

// DFS function to perform flood fill
void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    image[sr][sc] = newColor;

    // Explore the neighbors
    for (int i = 0; i < 4; i++) {
        if (isValid(image, sr + dx[i], sc + dy[i], oldColor)) {
            floodFill(image, sr + dx[i], sc + dy[i], newColor);
        }
    }
}

int main() {
    // Create a sample image
    vector<vector<int>> image = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
    int newColor = 2;

    // Perform flood fill
    floodFill(image, 0, 0, newColor);

    // Print the image after flood fill
    for (int i = 0; i < image.size(); i++) {
        for (int j = 0; j < image[0].size(); j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
