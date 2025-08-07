import sys
import math

def read_ints():
    return list(map(int, sys.stdin.readline().split()))

def find_interior_maxima(A, B, samples=20000):
    """
    Find all interior x in (0,2π) where y'(x)=0 and y''(x)<0.
    """
    def y1(x):
        return sum(a * math.cos(a*x + b) for a,b in zip(A, B))
    def y2(x):
        return sum(-a*a * math.sin(a*x + b) for a,b in zip(A, B))
    
    xs = [i * 2*math.pi / samples for i in range(samples+1)]
    d  = [y1(x) for x in xs]
    maxima = []
    
    # look for sign-change +→− in y'
    for i in range(samples):
        if d[i] > 0 and d[i+1] < 0:
            lo, hi = xs[i], xs[i+1]
            # refine by bisection
            for _ in range(30):
                mid = (lo + hi) / 2
                if y1(lo) * y1(mid) <= 0:
                    hi = mid
                else:
                    lo = mid
            xm = 0.5 * (lo + hi)
            # concavity check: y''(xm)<0 ⇒ local max
            if y2(xm) < 0:
                maxima.append(xm)
    return sorted(maxima)

def main():
    data = sys.stdin.read().strip().split()
    n    = int(data[0])
    A    = list(map(int, data[1:1+n]))
    B    = list(map(int, data[1+n:1+2*n]))
    
    # 1) Compute slope at x=0
    def y1_at_0():
        return sum(a * math.cos(b) for a,b in zip(A, B))
    
    peaks = []
    # 2) Include left endpoint as peak if slope there is negative
    if y1_at_0() < 0:
        peaks.append(0.0)
    
    # 3) Find all interior maxima
    peaks += find_interior_maxima(A, B)
    
    # 4) Compute valley widths between consecutive peaks
    widths = [peaks[i+1] - peaks[i] for i in range(len(peaks)-1)]
    
    # 5) Choose the valley index (1-based) with maximum width
    best_valley = max(range(len(widths)), key=lambda k: widths[k]) + 1
    
    print(best_valley)

if __name__ == "__main__":
    main()
