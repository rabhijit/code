from __future__ import print_function, division

import turtle


def koch(t, n):
    """n : length"""
    if n < 10:
        t.fd(n)
        return
    m = n/3
    koch(t, m)
    t.lt(60)
    koch(t, m)
    t.rt(120)
    koch(t, m)
    t.lt(60)
    koch(t, m)


def snowflake(t, n):
    for i in range(3):
        koch(t, n)
        t.rt(120)


t = turtle.Turtle()

t.pu()
t.goto(-150, 90)
t.pd()
snowflake(t, 300)

turtle.mainloop()
