class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x1 = max(A, E), x2 = min(C, G), y1 = max(B, F), y2 = min(D, H);
        int repeat = 0;
        if (x2 > x1 > 0 && y2 - y1 > 0) repeat = (x2 - x1)*(y2 - y1);
        return (C-A)*(D-B) + (G-E)*(H-F) - repeat;
    }
};
