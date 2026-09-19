class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // Find closest x-coordinate in rectangle
        int x = max(x1, min(xCenter, x2));

        // Find closest y-coordinate in rectangle
        int y = max(y1, min(yCenter, y2));

        // Distance between circle center and closest point
        int dx = x - xCenter;
        int dy = y - yCenter;

        // Compare squared distances
        return dx * dx + dy * dy <= radius * radius;
    }
};