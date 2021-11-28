from matplotlib import pyplot as plt
import sys

if len(sys.argv) == 2:
    title = sys.argv[1]
elif len(sys.argv) == 3:
    title = sys.argv[1]
    save_as = sys.argv[2]
else:
    title = ""
    save_as = None


Xi = []
Yi = []
Zi = []

with open("initial_points") as file:
    for line in file:
        x, y, z, _, _, _ = [float(i) for i in line.split(" ")]
        Xi.append(x)
        Yi.append(y)
        Zi.append(z)

Xc = []
Yc = []
Zc = []

for line in sys.stdin:
    x, y, z = [float(i) for i in line.split(" ")]
    Xc.append(x)
    Yc.append(y)
    Zc.append(z)

ax = plt.axes(projection='3d')

plt.plot(Xc, Yc, Zc, label="Curve")
plt.plot(Xi, Yi, Zi, label="Initial Points", alpha=0.3)
plt.legend()
plt.title(title)

if save_as:
    plt.savefig(save_as)
else:
    plt.show()
