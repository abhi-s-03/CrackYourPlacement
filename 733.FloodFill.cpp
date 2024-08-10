class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int inicolor){
        if(sr >= 0 && sc >= 0 && sr < image.size() && sc < image[0].size() 
           && image[sr][sc] == inicolor && image[sr][sc] != color){
            image[sr][sc] = color;
            dfs(image, sr+1, sc, color, inicolor);
            dfs(image, sr-1, sc, color, inicolor);
            dfs(image, sr, sc+1, color, inicolor);
            dfs(image, sr, sc-1, color, inicolor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] != color) {
            dfs(image, sr, sc, color, image[sr][sc]);
        }
        return image;
    }
};
