import matplotlib.pyplot as plt

# information for visualization
state_time = {"Aguascalientes":0,
        "Baja California":0,
        "Baja California Sur":0,
        "Campeche":0,
        "Chiapas":0,
        "Chihuahua":0,
        "CDMX":0,
        "Coahuila":0,
        "Colima":0,
        "Durango":0,
        "Guanajuato":0,
        "Guerrero":0,
        "Hidalgo":0,
        "Jalisco":0,
        "Estado de Mexico":0,
        "Michoacan":0,
        "Morelos":0,
        "Nayarit":0,
        "Nuevo Leon":0,
        "Oaxaca":0,
        "Puebla":0,
        "Queretaro":0,
        "Quintana Roo":0,
        "San Luis Potosi":0,
        "Sinaloa":0,
        "Sonora":0,
        "Tabasco":0,
        "Tamaulipas":0,
        "Tlaxcala":0,
        "Veracruz":0,
        "Yucatan":0,
        "Zacatecas":0}

# reading data
with open("trajectories.txt", "r") as f:
    lines = f.readlines()[3:-1]

for i, line in enumerate(lines): 
    lines[i] = line.split("|")
    lines[i].pop(0)
    lines[i].pop(3)
    for j, element in enumerate(lines[i]): 
        lines[i][j] = element.strip()
        if j == 1: lines[i][j] = float(lines[i][j])
        elif j == 2: lines[i][j] = int(lines[i][j])

# Parameters
traveling = 0.833 # km per second / 3000 km/hr / Mach 2.83 Airplane MiG-25 Foxbat
delivering = 1400 # gifts per second -> 56000 Christmas elves -> 40 teams of 1400 elves -> 20 seconds per gift and 20 seconds to rest and prepare for next gift 

# control
time, gift, total_distance = 0, 0, 0
TIME = [0]
GIFTS = [0]
DISTANCE = [0]

for line in lines:
    state, distance, delivers = line[0], line[1], line[2]
    # travel to the state
    while distance > 0:
        time += 1
        if distance >= traveling: total_distance += traveling
        else: total_distance += distance
        distance -= traveling
        TIME.append(time)
        GIFTS.append(gift)
        DISTANCE.append(total_distance)
    # deliver gifts to the state
    while delivers > 0:
        time += 1
        if delivers >= delivering: gift += delivering
        else: gift += delivers
        delivers -= delivering
        TIME.append(time)
        GIFTS.append(gift)
        DISTANCE.append(total_distance)
    # saving the time and distance when the delivery finished in the state
    state_time[state] = [time, total_distance, gift]

# printing results
print(f"Total distance: {total_distance}\nNumber of gifts delivered: {gift}\nTotal time (hr): {time/3600}")

# preparing information about the states
state_time = [(value[0], value[1], value[2], state) for state, value in state_time.items()]
state_time.sort()

# Plotting the amount of gifts delivered each second
fig1, ax1 = plt.subplots(figsize=(12,8))
ax1.axis([0, time, 0, gift])
ax1.scatter(TIME, GIFTS, color='red', s=0.0001)
ax1.set_xlabel('Seconds during Christmas Night', size=12)
ax1.set_ylabel('Amount of gifts delivered', size=12)
ax1.set_title('Plotting the amount of gifts delivered each second', size=16)
fig1.set_facecolor("mistyrose")
for t, d, g, state in state_time:
    ax1.axhline(y=g, color='lightcoral', linestyle='dotted', linewidth=0.8)
    ax1.text(x=t, y=g, s=state, color='brown', fontsize=8, alpha=0.8, rotation=0, ha='right')
for h in range(0, int(time), 3600):  
    ax1.axvline(x=h, color='lightcoral', linestyle='dotted', linewidth=0.8)
    ax1.text(h, 0, f'{h//3600}h', color='lightcoral', fontsize=8, rotation=90, verticalalignment='bottom')  

# Plotting distance traveled each second
fig2, ax2 = plt.subplots(figsize=(12,8))
ax2.axis([0, time, 0, total_distance])
ax2.scatter(TIME, DISTANCE, color='darkgreen', s=0.0001)
ax2.set_xlabel('Seconds during Christmas Night', size=12)
ax2.set_ylabel('Total distance traveled (km)', size=12)
ax2.set_title('Plotting distance traveled each second', size=16)
fig2.set_facecolor("lightgreen")
for t, d, g, state in state_time:
    ax2.axhline(y=d, color='lightseagreen', linestyle='dotted', linewidth=0.8)
    ax2.text(x=t, y=d, s=state, color='teal', fontsize=8, alpha=0.8, rotation=0, ha='right')
for h in range(0, int(time), 3600):  
    ax2.axvline(x=h, color='lightseagreen', linestyle='dotted', linewidth=0.8)
    ax2.text(h, 0, f'{h//3600}h', color='lightseagreen', fontsize=8, rotation=90, verticalalignment='bottom')  

plt.show()
