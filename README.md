# 🧟‍♂️ Code vs Zombies

This program solves the **Code vs Zombies** challenge by prioritizing saving humans who are in immediate danger and moving the player character (Ash) toward the zombie that will reach a human the soonest.

---

## 🚀 How It Works

On every game turn, the algorithm:

1. **Reads all current positions** of Ash, humans, and zombies.
2. **Identifies the most endangered human** by locating the closest zombie to each human and estimating:
   - How long a zombie will take to reach that human.
   - How long Ash will take to reach shooting range of that zombie.
3. **Chooses the zombie/human pair with the smallest positive time difference**, meaning Ash can still save that human.
4. **Targets that zombie**, prioritizing immediate defense over long-term exploration.
5. **Performs local optimization (hill climbing)** around the selected target to refine the movement direction.
6. **Outputs target coordinates**, causing Ash to move 1000 units toward that position.

This approach is focused on **practical survivability**:  
It tries to guarantee at least one human remains alive while still maximizing zombie eliminations.

---

## 🧠 Techniques Used

The solution uses a **combinational heuristic** with basic **local search (Hill Climbing)**.

### Algorithmic Concepts

- **Greedy Decision-Making**  
  Selects the zombie that threatens any human the soonest, ensuring the AI reacts quickly to danger.

- **Time-Based Heuristic**  
  Estimates:
  - Time for each zombie to reach a human.
  - Time for Ash to reach lethal shooting range.  
  These values determine whether a human is “savable.”

- **Hill Climbing (Local Optimization)**  
  After choosing an initial target, the algorithm:
  - Tests a small grid of candidate positions around it (±800 and ±400 offsets).
  - Computes a simple score based on proximity to zombies.
  - Picks the best local position.  
  This improves targeting direction without full simulation or random search.

---

## 📌 Goal

Keep humans alive while eliminating as many zombies as possible, using efficient, fast, and deterministic decision-making.

---

Feel free to explore, modify, or improve the strategy!
