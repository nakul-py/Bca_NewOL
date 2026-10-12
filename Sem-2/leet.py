first_number = int(input())
data = []

while first_number > 0:
    a = input()
    data.append(a)
    first_number -= 1

for i in range(len(data)):
    a = data[i]

    if len(a) != 4:
        print("NO")
       
    else:
        if a[0] == a[1] == a[2] == a[3]:
            print("YES")
        else:
            print("NO")

print(data)










# for j in data:
#     if len(j) != 4:
#         print("NO")

#     for k in j:
#         if k != 1:
#             print("NO")
#             break
#         if j[0] == j[1] == j[2] == j[3]:
#             print("YES")

#     else:
#         print("NO")

# print(data)
