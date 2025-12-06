This program solves the “Code vs Zombies” problem by prioritizing saving humans who are in immediate danger and moving the player character (Ash) toward the zombie that is about to reach a human next.

For every turn, the algorithm:

Reads all current positions of Ash, humans, and zombies.

Identifies the most endangered human by finding the closest zombie to each human and estimating:

how long a zombie will take to reach that human, and

how long Ash will take to reach shooting range of that zombie.

Chooses the zombie/human pair with the smallest positive time difference (meaning Ash can still get there in time).

Selects that zombie’s position as the target.

Performs a small local optimization around the chosen target to slightly adjust and improve the move direction.

Outputs target coordinates so Ash moves 1000 units toward that position.

This approach is focused on practical survivability: it tries to ensure that at least one human remains alive while maximizing zombie eliminations.


Techniques Used

This solution uses a combinational heuristic with basic local search (Hill Climbing).

Algorithmic Concepts Used:

Greedy Decision-Making
The bot selects the zombie that threatens any human the soonest, ensuring urgent defense rather than long-term planning.

Time-Based Heuristic
The algorithm estimates:

Time for each zombie to reach a human

Time for Ash to reach lethal range
and uses these calculated values to decide whether a human is “savable.”

Hill Climbing (Local Optimization)
After selecting a base target, the program:

Tests a small grid of candidate positions around the target (±800 and ±400 offsets)

Computes a simple score based on proximity to zombies

Chooses the best local position
This improves targeting direction without full simulation or random search.
