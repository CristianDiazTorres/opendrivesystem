
#define Clipper_Contains_Point(pt) \
    (s_minX <= pt.Clipper_X_Element \
    && s_minY <= pt.Clipper_Y_Element \
    && s_maxX >= pt.Clipper_X_Element \
    && s_maxY >= pt.Clipper_Y_Element)

namespace _NMath
{

template <typename BoundComponentType,
          typename BoundType,
          typename PointComponentType,
          typename PointTypeToClip,
          typename PointTypeToReturn>
class Clipper
{
public:
    typedef QVector< PointTypeToClip >	PointTypeToClipV;
    typedef QVector< PointTypeToClipV >	PointTypeToClipVV;

    typedef QVector< PointTypeToReturn >	PointTypeToReturnV;
    typedef QVector< PointTypeToReturnV >	PointTypeToReturnVV;

public:
    static BoundComponentType		s_minX;
    static BoundComponentType		s_minY;
    static BoundComponentType		s_maxX;
    static BoundComponentType		s_maxY;
    static PointTypeToClipV			s_curve;

    static PointTypeToClip			s_prev;
    static PointComponentType		s_prevX;
    static PointComponentType		s_prevY;

    static PointTypeToClip			s_cur;
    static PointComponentType		s_curX;
    static PointComponentType		s_curY;

    static int						s_interCount;
    static PointComponentType		s_i1x;
    static PointComponentType		s_i1y;
    static PointComponentType		s_i2x;
    static PointComponentType		s_i2y;

    static PointComponentType		s_d1x;
    static PointComponentType		s_d1y;
    static PointComponentType		s_d2x;
    static PointComponentType		s_d2y;

    static PointComponentType		s_tmpComponent;

public:
    template <typename T>
    static inline T Clipper_abs(const T &value)
    {
        return value >= 0 ? value : - value;
    }

    static inline int Clipper_abs(int value)
    {
        return ::abs(value);
    }

    static inline float Clipper_abs(float value)
    {
        return ::fabs(value);
    }

    static inline double Clipper_abs(double value)
    {
        return ::fabs(value);
    }

    static inline void setBound(const QRect &bound)
    {
        s_minX = bound.x1;
        s_minY = bound.y1;
        s_maxX = bound.x2;
        s_maxY = bound.y2;
    }

    static inline void setBound(const QRectF &bound)
    {
        s_minX = bound.left();
        s_minY = bound.top();
        s_maxX = bound.right();
        s_maxY = bound.bottom();
    }

    static inline void getInterPoints()
    {
        bool xeq = s_prevX == s_curX;
        bool yeq = s_prevY == s_curY;

        if (xeq)
        {
            if (yeq)
            {
                s_interCount = 0;
            }
            else
            {
                Clipper_Inter_V_TB(s_interCount = , s_prevX, s_prevY, s_curY, s_minX, s_minY, s_maxX, s_maxY, s_i1x, s_i1y, s_i2x, s_i2y);
            }
        }
        else if (yeq)
        {
            Clipper_Inter_H_LR(s_interCount = , s_prevX, s_curX, s_prevY, s_minX, s_minY, s_maxX, s_maxY, s_i1x, s_i1y, s_i2x, s_i2y);
        }
        else
        {
            Clipper_Inter_NHNV_Box(s_interCount = , s_prevX, s_prevY, s_curX, s_curY, s_minX, s_minY, s_maxX, s_maxY, s_i1x, s_i1y, s_i2x, s_i2y, s_d1x, s_d1y, s_d2x, s_d2y, s_tmpComponent);
        }
    }

    static inline void getClippedLines(PointTypeToReturnV &ret)
    {
        if (s_curve.size() < 2)
            return;

        bool prevInside;

        bool curInside = Clipper_Contains_Point(s_curve.first());

        for (int i = 1; i < s_curve.size(); i ++)
        {
            s_prev = s_curve[i - 1];
            s_cur = s_curve[i];

            prevInside = curInside;

            curInside = Clipper_Contains_Point(s_cur);

            if (prevInside && curInside)
            {
                ret << s_prev << s_cur;
                continue;
            }

            s_prevX = s_prev.Clipper_X_Element;
            s_prevY = s_prev.Clipper_Y_Element;
            s_curX = s_cur.Clipper_X_Element;
            s_curY = s_cur.Clipper_Y_Element;

            getInterPoints();

            if (s_interCount == 2)
            {
                ret << PointTypeToClip(s_i1x, s_i1y) << PointTypeToClip(s_i2x, s_i2y);
            }
            else if (s_interCount == 1)
            {
                if (prevInside)
                {
                    if (s_prevX != s_i1x || s_prevY != s_i1y)
                    {
                        ret << s_prev << PointTypeToClip(s_i1x, s_i1y);
                    }
                }
                else if (curInside)
                {
                    if (s_curX != s_i1x || s_curY != s_i1y)
                    {
                        ret << PointTypeToClip(s_i1x, s_i1y) << s_cur;
                    }
                }
            }
        }
    }

    static inline void getClippedLines(const PointTypeToClipV &curve, PointTypeToReturnV &ret)
    {
        s_curve = curve;
        getClippedLines(ret);
    }

    static inline void getClippedLines(const QRect &bound, const PointTypeToClipV &curve, PointTypeToReturnV &ret)
    {
        setBound(bound);
        getClippedLines(curve, ret);
    }

    static inline void getClippedLines(const QRectF &bound, const PointTypeToClipV &curve, PointTypeToReturnV &ret)
    {
        setBound(bound);
        getClippedLines(curve, ret);
    }

    static inline void getClippedLines(const PointTypeToClipVV &poly, PointTypeToReturnV &ret)
    {
        for (int i = 0; i < poly.size(); i ++)
            getClippedLines(poly[i], ret);
    }

    static inline void getClippedLines(const QRect &bound, const PointTypeToClipVV &poly, PointTypeToReturnV &ret)
    {
        setBound(bound);
        getClippedLines(poly, ret);
    }

    static inline void getClippedLines(const QRectF &bound, const PointTypeToClipVV &poly, PointTypeToReturnV &ret)
    {
        setBound(bound);
        getClippedLines(poly, ret);
    }

    static inline void getClippedLineStrips(PointTypeToReturnVV &ret)
    {
        if (s_curve.size() < 2)
            return;

        bool prevInside;

        bool curInside = Clipper_Contains_Point(s_curve.first());
        if (curInside)
        {
            ret << PointTypeToReturnV();
            ret.last() << s_curve.first();
        }

        for (int i = 1; i < s_curve.size(); i ++)
        {
            s_prev = s_curve[i - 1];
            s_cur = s_curve[i];

            prevInside = curInside;

            curInside = Clipper_Contains_Point(s_cur);

            if (prevInside && curInside)
            {
                ret.last() << s_cur;
                continue;
            }

            s_prevX = s_prev.Clipper_X_Element;
            s_prevY = s_prev.Clipper_Y_Element;
            s_curX = s_cur.Clipper_X_Element;
            s_curY = s_cur.Clipper_Y_Element;

            getInterPoints();

            if (s_interCount == 2)
            {
                if (prevInside)
                {
                    if (s_prevX == s_i1x && s_prevY == s_i1y)
                    {
                        ret.last() << PointTypeToReturn(s_i2x, s_i2y);
                    }
                    else
                    {
                        ret.last() << PointTypeToReturn(s_i1x, s_i1y);
                    }
                }
                else
                {
                    ret << PointTypeToReturnV();
                    ret.last() << PointTypeToReturn(s_i1x, s_i1y) << PointTypeToReturn(s_i2x, s_i2y);
                }
            }
            else if (s_interCount == 1)
            {
                if (prevInside)
                {
                    if (s_prevX != s_i1x || s_prevY != s_i1y)
                    {
                        ret.last() << PointTypeToReturn(s_i1x, s_i1y);
                    }
                }
                else if (curInside)
                {
                    ret << PointTypeToReturnV();

                    if (s_curX != s_i1x || s_curY != s_i1y)
                    {
                        ret.last() << PointTypeToReturn(s_i1x, s_i1y);
                    }

                    ret.last() << s_cur;
                }
            }
        }
    }

    static inline void getClippedLineStrips(const PointTypeToClipV &curve, PointTypeToReturnVV &ret)
    {
        s_curve = curve;
        getClippedLineStrips(ret);
    }

    static inline void getClippedLineStrips(const QRect &bound, const PointTypeToClipV &curve, PointTypeToReturnVV &ret)
    {
        setBound(bound);
        getClippedLineStrips(curve, ret);
    }

    static inline void getClippedLineStrips(const QRectF &bound, const PointTypeToClipV &curve, PointTypeToReturnVV &ret)
    {
        setBound(bound);
        getClippedLineStrips(curve, ret);
    }

    static inline void getClippedLineStrips(const PointTypeToClipVV &poly, PointTypeToReturnVV &ret)
    {
        for (int i = 0; i < poly.size(); i ++)
            getClippedLineStrips(poly[i], ret);
    }

    static inline void getClippedLineStrips(const QRect &bound, const PointTypeToClipVV &poly, PointTypeToReturnVV &ret)
    {
        setBound(bound);
        getClippedLineStrips(poly, ret);
    }

    static inline void getClippedLineStrips(const QRectF &bound, const PointTypeToClipVV &poly, PointTypeToReturnVV &ret)
    {
        setBound(bound);
        getClippedLineStrips(poly, ret);
    }
};

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
BoundComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_minX;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
BoundComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_minY;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
BoundComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_maxX;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
BoundComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_maxY;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
typename Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::PointTypeToClipV
Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_curve;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointTypeToClip				Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_prev;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_prevX;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_prevY;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointTypeToClip				Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_cur;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_curX;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_curY;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
int						Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_interCount;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_i1x;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_i1y;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_i2x;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_i2y;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_d1x;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_d1y;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_d2x;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_d2y;

template <typename BoundComponentType, typename BoundType, typename PointComponentType, typename PointTypeToClip, typename PointTypeToReturn>
PointComponentType		Clipper<BoundComponentType, BoundType, PointComponentType, PointTypeToClip, PointTypeToReturn>::s_tmpComponent;

}
