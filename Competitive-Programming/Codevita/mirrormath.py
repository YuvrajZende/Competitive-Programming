num = input().strip()
s = input().strip()

left_right = {'0': '0', '1': '1', '2': '5', '5': '2', '8': '8'}
up = {'0': '0', '8': '8'}
down = {'0': '0', '1': '1', '2': '5', '8': '8'}

res = []

for i in range(min(len(num), len(s))):
    digit = num[i]
    img = s[i]
    result = None

    if img == 'S':
        result = digit
    elif img in ('L', 'R'):
        result = left_right.get(digit)
    elif img == 'D':
        result = down.get(digit)
    elif img == 'U':
        result = up.get(digit)

    if result is not None:
        res.append(result)

res.sort()

if len(res) > 1 and res[0] == '0':
    for i in range(1, len(res)):
        if res[i] != '0':
            res[0], res[i] = res[i], res[0]
            break

print("".join(res) if res else "0")