import turtle
import math
def piedraw(t, n, d):
    """ t = turtle
        n = number of pies
        d = length of pies from ctr """
    intangle = 360 / n
    extangle = (180 - intangle) / 2
    t.lt(intangle / 2)
    t.fd(d)
    t.lt(180 - extangle)
    for i in range(n):
        t.fd((d * math.sin(intangle * (math.pi / 180))) / math.sin(extangle * math.pi / 180))
        t.lt(180 - extangle)
        t.fd(d)
        t.bk(d)
        t.rt(extangle)

    turtle.mainloop()

bob = turtle.Turtle()
piedraw(bob, 5, 60)
