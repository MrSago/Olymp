"""
ID: deadly51
TASK: beads
LANG: PYTHON3
"""

with open("beads.in", "r") as file:
    n = int(file.readline().strip())
    necklace = file.readline().strip()

necklace += necklace
left = [[0 for _ in range(2)] for _ in range(len(necklace) + 1)]
right = [[0 for _ in range(2)] for _ in range(len(necklace) + 1)]
left[0][0] = 0
left[0][1] = 0
right[len(necklace)][0] = 0
right[len(necklace)][1] = 0
for i in range(1, len(necklace)):
    if necklace[i-1] == "r":
        left[i][0] = left[i-1][0] + 1
    elif necklace[i-1] == "b":
        left[i][1] = left[i-1][1] + 1
    else:
        left[i][0] = left[i-1][0] + 1
        left[i][1] = left[i-1][1] + 1
for i in range(len(necklace)-1, -1, -1):
    if necklace[i] == "r":
        right[i][0] = right[i+1][0] + 1
    elif necklace[i] == "b":
        right[i][1] = right[i+1][1] + 1
    else:
        right[i][0] = right[i+1][0] + 1
        right[i][1] = right[i+1][1] + 1

max_sequence_len = 0
for i in range(len(necklace)):
    max_sequence_len = max(max_sequence_len, max(left[i][0], left[i][1]) + max(right[i][0], right[i][1]))
max_sequence_len = n if max_sequence_len > n else max_sequence_len
with open("beads.out", "w") as file:
    file.write(str(max_sequence_len)+"\n")
