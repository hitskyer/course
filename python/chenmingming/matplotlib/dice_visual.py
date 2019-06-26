from dice import Dice
import pygal
d6_1 = Dice()
d6_2 = Dice()
results = []
for roll_num in range(100000):
    result = d6_1.roll() * d6_2.roll()
    results.append(result)
frequencies = []
for value in range(1, 37):
    if results.count(value):
        frequency = results.count(value)
        frequencies.append(frequency)
x_data = []
for value in range(1, 37):
    if value in results:
        x_data.append(value)
hist = pygal.Bar()
hist.title = "Results of rolling two D6 100000 times."
hist.x_labels = x_data
hist.x_title = "Result"
hist.y_title = "Frequency of Result"
hist.add('D6*D6', frequencies)
hist.render_to_file("dice_visual.svg")
print(frequencies)