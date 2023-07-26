
#define Clipper_Inter_V_TB(retCommand, x, y1, y2, minX, minY, maxX, maxY, i1x, i1y, i2x, i2y) \
    if (x >= minX && x <= maxX) \
{ \
    if (y1 >= maxY) \
{ \
    if (y2 <= minY) \
{ \
    i1x = i2x = x; \
    i1y = maxY; \
    i2y = minY; \
    retCommand 2; \
    } \
    else if (y2 <= maxY) \
{ \
    i1x = x; \
    i1y = maxY; \
    retCommand 1; \
    } \
    else \
{ \
    retCommand 0; \
    } \
    } \
    else if (y1 > minY) \
{ \
    if (y2 >= maxY) \
{ \
    i1x = x; \
    i1y = maxY; \
    retCommand 1; \
    } \
    else if (y2 <= minY) \
{ \
    i1x = x; \
    i1y = minY; \
    retCommand 1; \
    } \
    else \
{ \
    retCommand 0; \
    } \
    } \
    else /* if (y1 <= minY) */ \
{ \
    if (y2 >= maxY) \
{ \
    i1x = i2x = x; \
    i1y = minY; \
    i2y = maxY; \
    retCommand 2; \
    } \
    else if (y2 >= minY) \
{ \
    i1x = x; \
    i1y = minY; \
    retCommand 1; \
    } \
    else \
{ \
    retCommand 0; \
    } \
    } \
    } \
    else \
{ \
    retCommand 0; \
    }

#define Clipper_Inter_H_LR(retCommand, x1, x2, y, minX, minY, maxX, maxY, i1x, i1y, i2x, i2y) \
    if (y >= minY && y <= maxY) \
{ \
    if (x1 >= maxX) \
{ \
    if (x2 <= minX) \
{ \
    i1y = i2y = y; \
    i1x = maxX; \
    i2x = minX; \
    retCommand 2; \
    } \
    else if (x2 <= maxX) \
{ \
    i1y = y; \
    i1x = maxX; \
    retCommand 1; \
    } \
    else \
{ \
    retCommand 0; \
    } \
    } \
    else if (x1 > minX) \
{ \
    if (x2 >= maxX) \
{ \
    i1y = y; \
    i1x = maxX; \
    retCommand 1; \
    } \
    else if (x2 <= minX) \
{ \
    i1y = y; \
    i1x = minX; \
    retCommand 1; \
    } \
    else \
{ \
    retCommand 0; \
    } \
    } \
    else /* if (x1 <= minX) */ \
{ \
    if (x2 >= maxX) \
{ \
    i1y = i2y = y; \
    i1x = minX; \
    i2x = maxX; \
    retCommand 2; \
    } \
    else if (x2 >= minX) \
{ \
    i1y = y; \
    i1x = minX; \
    retCommand 1; \
    } \
    else \
{ \
    retCommand 0; \
    } \
    } \
    } \
    else \
{ \
    retCommand 0; \
    }

#define Clipper_Inter_NHNV_V(x1, y1, x2, y2, x, minY, maxY, hasInter, ix, iy) \
    if ((x1 >= x && x2 <= x) || (x1 <= x && x2 >= x)) \
{ \
    iy = y1 + (y2 - y1) * (x - x1) / (x2 - x1); \
    if (iy >= minY && iy <= maxY) \
{ \
    hasInter = true; \
    ix = x; \
    } \
    else \
{ \
    hasInter = false; \
    } \
    } \
    else \
{ \
    hasInter = false; \
    }

#define Clipper_Inter_NHNV_L(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, ix, iy) \
    Clipper_Inter_NHNV_V(x1, y1, x2, y2, minX, minY, maxY, hasInter, ix, iy)

#define Clipper_Inter_NHNV_R(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, ix, iy) \
    Clipper_Inter_NHNV_V(x1, y1, x2, y2, maxX, minY, maxY, hasInter, ix, iy)

#define Clipper_Inter_NHNV_H(x1, y1, x2, y2, y, minX, maxX, hasInter, ix, iy) \
    if ((y1 >= y && y2 <= y) || (y1 <= y && y2 >= y)) \
{ \
    ix = x1 + (x2 - x1) * (y - y1) / (y2 - y1); \
    if (ix >= minX && ix <= maxX) \
{ \
    hasInter = true; \
    iy = y; \
    } \
    else \
{ \
    hasInter = false; \
    } \
    } \
    else \
{ \
    hasInter = false; \
    }

#define Clipper_Inter_NHNV_T(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, ix, iy) \
    Clipper_Inter_NHNV_H(x1, y1, x2, y2, minY, minX, maxX, hasInter, ix, iy)

#define Clipper_Inter_NHNV_B(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, ix, iy) \
    Clipper_Inter_NHNV_H(x1, y1, x2, y2, maxY, minX, maxX, hasInter, ix, iy)

#define Clipper_Inter_ReOrder(x1, y1, i1x, i1y, i2x, i2y, d1x, d1y, d2x, d2y, tmp) \
    d1x = Clipper_abs(i1x - x1); \
    d2x = Clipper_abs(i2x - x1); \
    if (d1x > d2x) \
{ \
    tmp = i1x; i1x = i2x; i2x = tmp; \
    tmp = i1y; i1y = i2y; i2y = tmp; \
    } \
    else if (d1x == d2x) \
{ \
    d1y = Clipper_abs(i1y - y1); \
    d2y = Clipper_abs(i2y - y1); \
    if (d1y > d2y) \
{ \
    tmp = i1x; i1x = i2x; i2x = tmp; \
    tmp = i1y; i1y = i2y; i2y = tmp; \
    } \
    }

#define Clipper_Inter_NHNV_Box(retCommand, x1, y1, x2, y2, minX, minY, maxX, maxY, i1x, i1y, i2x, i2y, d1x, d1y, d2x, d2y, tmp) \
    bool hasInter; \
    Clipper_Inter_NHNV_L(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, i1x, i1y); \
    if (hasInter) \
{ \
    Clipper_Inter_NHNV_R(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, i2x, i2y); \
    if (hasInter) \
{ \
    Clipper_Inter_ReOrder(x1, y1, i1x, i1y, i2x, i2y, d1x, d1y, d2x, d2y, tmp) \
    retCommand 2; \
    } \
    else \
{ \
    Clipper_Inter_NHNV_T(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, i2x, i2y); \
    if (hasInter) \
{ \
    if (i1x == i2x && i1y == i2y) \
{ \
    Clipper_Inter_NHNV_B(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, i2x, i2y); \
    if (hasInter) \
{ \
    Clipper_Inter_ReOrder(x1, y1, i1x, i1y, i2x, i2y, d1x, d1y, d2x, d2y, tmp) \
    retCommand 2; \
    } \
    else \
{ \
    retCommand 1; \
    } \
    } \
    else \
{ \
    Clipper_Inter_ReOrder(x1, y1, i1x, i1y, i2x, i2y, d1x, d1y, d2x, d2y, tmp) \
    retCommand 2; \
    } \
    } \
    else \
{ \
    Clipper_Inter_NHNV_B(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, i2x, i2y); \
    if (hasInter) \
{ \
    if (i1x == i2x && i1y == i2y) \
{ \
    retCommand 1; \
    } \
    else \
{ \
    Clipper_Inter_ReOrder(x1, y1, i1x, i1y, i2x, i2y, d1x, d1y, d2x, d2y, tmp) \
    retCommand 2; \
    } \
    } \
    else \
{ \
    retCommand 1; \
    } \
    } \
    } \
    } \
    else \
{ \
    Clipper_Inter_NHNV_R(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, i1x, i1y); \
    if (hasInter) \
{ \
    Clipper_Inter_NHNV_T(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, i2x, i2y); \
    if (hasInter) \
{ \
    if (i1x == i2x && i1y == i2y) \
{ \
    Clipper_Inter_NHNV_B(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, i2x, i2y); \
    if (hasInter) \
{ \
    Clipper_Inter_ReOrder(x1, y1, i1x, i1y, i2x, i2y, d1x, d1y, d2x, d2y, tmp) \
    retCommand 2; \
    } \
    else \
{ \
    retCommand 1; \
    } \
    } \
    else \
{ \
    Clipper_Inter_ReOrder(x1, y1, i1x, i1y, i2x, i2y, d1x, d1y, d2x, d2y, tmp) \
    retCommand 2; \
    } \
    } \
    else \
{ \
    Clipper_Inter_NHNV_B(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, i2x, i2y); \
    if (hasInter) \
{ \
    if (i1x == i2x && i1y == i2y) \
{ \
    retCommand 1; \
    } \
    else \
{ \
    Clipper_Inter_ReOrder(x1, y1, i1x, i1y, i2x, i2y, d1x, d1y, d2x, d2y, tmp) \
    retCommand 2; \
    } \
    } \
    else \
{ \
    retCommand 1; \
    } \
    } \
    } \
    else \
{ \
    Clipper_Inter_NHNV_T(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, i1x, i1y); \
    if (hasInter) \
{ \
    Clipper_Inter_NHNV_B(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, i2x, i2y); \
    if (hasInter) \
{ \
    Clipper_Inter_ReOrder(x1, y1, i1x, i1y, i2x, i2y, d1x, d1y, d2x, d2y, tmp) \
    retCommand 2; \
    } \
    else \
{ \
    retCommand 1; \
    } \
    } \
    else \
{ \
    Clipper_Inter_NHNV_B(x1, y1, x2, y2, minX, minY, maxX, maxY, hasInter, i1x, i1y); \
    if (hasInter) \
{ \
    retCommand 1; \
    } \
    else \
{ \
    retCommand 0; \
    } \
    } \
    } \
    }


