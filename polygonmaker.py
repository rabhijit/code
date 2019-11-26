import turtle

def square(t, length):
    for i in range(0,4):
        t.fd(length)
        t.lt(90)

def polygon(t, n, length):
    for i in range(0,n):
        t.fd(length)
        t.lt(360.00 / n)

def circle(t, r):
    polygon(t, r, 2 * 3.1415926)

def arc(t, r, angle):
    for i in range(0, int(r / (360.0 / angle))):
        t.fd(2 * 3.1415926)
        t.lt(360.00 / r)
    t.lt(90)
    t.fd(r)
    t.lt(180 - angle)
    t.fd(r)

bob = turtle.Turtle()
arc(bob, 50, 285)
