#calculate 0 to time cost
def calRecond(time, rate):
    res =  float(time[1] * 60.0 * rate[24] + time[3] * rate[time[2]]);
    for i in range(time[2]):
        res += 60 * rate[i];
    return res / 100

#input rate
rate = map(int, raw_input().strip().split())
rate.append(sum(rate))
#input n
n = int(raw_input().strip())
#input recond [name mm:dd:hh:mm onORoff]
reconds = []
for i in range(n):
    cin = map(str, raw_input().strip().split())
    time = map(int, cin[1].split(':'))
    recond = [cin[0], time, cin[2], time[1] * 24 * 60 + time[2] * 60 + time[3]]
    reconds.append(recond)
reconds.sort(key = lambda rec:(rec[0], rec[3]))
#choose match recond
customers = []
name = ""
for i in range(1, n):
    pre = reconds[i - 1]
    now = reconds[i]
    if pre[0] == now[0]:
        if pre[2] == "on-line" and now[2] == "off-line":
            if name == "" or name != pre[0]:
                customers.append([])
                name = pre[0]
            customers[len(customers) - 1].append(pre)
            customers[len(customers) - 1].append(now)
#output
for customer in customers:
    print "%s %02d" % (customer[0][0], customer[0][1][0])
    charge = 0
    for i in range(1, len(customer), 2):
        pre = customer[i - 1]
        now = customer[i]
        temp = calRecond(now[1], rate) - calRecond(pre[1], rate)
        charge += temp
        print "%02d:%02d:%02d" % (pre[1][1], pre[1][2], pre[1][3]),
        print "%02d:%02d:%02d" % (now[1][1], now[1][2], now[1][3]),
        print "%d $%.2f" % (now[3] - pre[3], temp)
    print "Total amount: $%.2f" % charge