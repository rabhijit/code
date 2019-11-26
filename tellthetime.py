import time
timer = time.time()

days = timer / 60 / 60 // 24
hours = (timer / 60 / 60) % 24
minutes = (timer / 60) % 60
seconds = timer % 60
print('\n', timer, '\n')
print('It has been: %.3f days, %.3f hours, %.3f minutes, and %.3f seconds since the epoch.\n' % (days, hours, minutes, seconds))

print("The time now is:")
print(" " * 30, "%d:%d:%d" % ((hours // 1), (minutes // 1), (seconds // 1)))
