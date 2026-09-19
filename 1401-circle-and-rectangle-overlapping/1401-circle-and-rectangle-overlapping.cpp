class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        // check intersection with left vertical line of rect. with circle
        float k = yCenter * yCenter - radius * radius +
                  (x1 - xCenter) * (x1 - xCenter);
        float yRoot1 = yCenter - sqrt(yCenter * yCenter - k);
        float yRoot2 = yCenter + sqrt(yCenter * yCenter - k);
        if ((y1 <= yRoot1 && yRoot1 <= y2) || (y1 <= yRoot2 && yRoot2 <= y2)) {
            return true;
        }

        // check intersection with right vertical line of rect. with circle
        k = yCenter * yCenter - radius * radius +
            (x2 - xCenter) * (x2 - xCenter);
        yRoot1 = yCenter - sqrt(yCenter * yCenter - k);
        yRoot2 = yCenter + sqrt(yCenter * yCenter - k);
        if ((y1 <= yRoot1 && yRoot1 <= y2) || (y1 <= yRoot2 && yRoot2 <= y2)) {
            return true;
        }

        // check intersection with top horizontal line of rect. with circle
        k = xCenter * xCenter - radius * radius +
            (y1 - yCenter) * (y1 - yCenter);
        float xRoot1 = xCenter - sqrt(xCenter * xCenter - k);
        float xRoot2 = xCenter - sqrt(xCenter * xCenter - k);
        ;
        if ((x1 <= xRoot1 && xRoot1 <= x2) || (x1 <= xRoot2 && xRoot2 <= x2)) {
            return true;
        }

        // check intersection with bottom horizontal line of rect. with circle
        k = xCenter * xCenter - radius * radius +
            (y2 - yCenter) * (y2 - yCenter);
        xRoot1 = xCenter - sqrt(xCenter * xCenter - k);
        xRoot2 = xCenter + sqrt(xCenter * xCenter - k);
        if ((x1 <= xRoot1 && xRoot1 <= x2) || (x1 <= xRoot2 && xRoot2 <= x2)) {
            return true;
        }

        // isCompletely inside of one another
        // circle is completely inside rect.
        if ((x1 <= xCenter && xCenter <= x2) &&
            (y1 <= yCenter && yCenter <= y2)) {
            return true;
        }
        // rect. is completely inside
        float pt = (x1 - xCenter) * (x1 - xCenter) +
                   (y1 - yCenter) * (y1 - yCenter) - radius * radius;
        if (pt <= 0) {
            return true;
        }

        return false;
    }
};