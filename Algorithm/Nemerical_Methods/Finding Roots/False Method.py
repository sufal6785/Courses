def f(x):
    return x * x - 4 * x - 10


def falsi(a, b, tol=1e-6, max_iter=1000):

    if a >= b:
        raise ValueError("Invalid interval: a must be < b")

    fa = f(a)
    fb = f(b)

    if fa * fb > 0:
        raise ValueError("f(a) and f(b) must have opposite signs")

    for _ in range(max_iter):

        mid = (a * fb - b * fa) / (fb - fa)
        fm = f(mid)

        # stopping criteria: function value small OR interval sufficiently small
        if abs(fm) < tol or (b - a) / 2.0 < tol:
            return mid

        if fa * fm < 0:
            b = mid
            fb = fm
        else:
            a = mid
            fa = fm

    # if not converged, return best estimate
    return (a + b) / 2.0


def find_bracket(start, dx, max_steps=10000):
    a = start
    b = start + dx

    for _ in range(max_steps):
        if f(a) * f(b) < 0:
            return a, b
        a = b
        b = b + dx

    raise RuntimeError("No sign change found in scanning range")


def main():
    start = -100.0
    dx = 1.0
    try:
        a, b = find_bracket(start, dx)
        root = falsi(a, b, tol=1e-6)
        print("Root:", root)

    except Exception as e:
        print("Error:", e)


if __name__ == "__main__":
    main()
