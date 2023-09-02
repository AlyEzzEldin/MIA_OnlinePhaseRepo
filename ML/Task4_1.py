from cmath import inf
import random
import time

class Villain :
    def __init__(self,name,health = 100) :
        self.name = name
        self.health = health
        self.energy = 500
        self.shield = 0

    def take_damage(self,damage) :
        damage = damage - self.shield
        if damage > 0 :
            self.health =self.health - damage

    def use_weapon(self,enemy,weapon) :
        pass    

    def use_shield(self,shield) :
        pass

class Weapon : 
    def __init__(self,name,energy ,damage,resources) :
        self.name = name
        self.energy = energy
        self.damage = damage
        self.resources = resources

    def use(self,villain,enemy) : 
        villain.use_weapon(enemy,self)

class Shield :
    def __init__(self,name,energy,save,resources) :
        self.name = name
        self.energy = energy
        self.save = save
        self.resources = resources
    
    def use(self,villain) :
        villain.use_shield(self)

class Gru(Villain) :
    def use_weapon(self, enemy, weapon):
        if weapon.name == "Freeze Gun" :
            enemy.take_damage(weapon.damage)
        elif weapon.name == "Electric Prod" :
            enemy.take_damage(weapon.damage)
        elif weapon.name == "Mega Magnet" :
            enemy.take_damage(int(weapon.damage * 0.8))
        elif weapon.name == "Kalman Missile" :
            enemy.take_damage(weapon.damage)

    def use_shield(self, shield):
        if shield.name == "Energy-Projected BarrierGun" :
            self.shield += int(shield.save * shield.energy)
        elif shield.name == "Selective Permeability" :
            self.shield += int(shield.save * shield.energy)

class Vector(Villain) :
    def use_weapon(self, enemy, weapon):
        if weapon.name == "Laser Blasters" :
            enemy.take_damage(weapon.damage)
        elif weapon.name == "Plasma Grenades" :
            enemy.take_damage(weapon.damage)
        elif weapon.name == "Sonic Resonance Cannon" :
            enemy.take_damage(weapon.damage)
    
    def use_shield(self, shield):
        if shield.name == "Energy Net Trap" :
            self.shield += int(shield.save * shield.energy)
        elif shield.name == "Quantum Deflector" :
            self.shield += int(shield.save * shield.energy)

class Wizard :
    def __init__(self) :
        self.weapons=[]
        self.shields=[]
    
    def add_weapon(self,weapon) :
        self.weapons.append(weapon)

    def add_shield(self,shield) :
        self.shields.append(shield)

    def choose_weapon(self,villain) :
        return random.choice(self.weapons)
     
    def choose_shield(self,villain) :
        return random.choice(self.shields)
    
def simulate_battle():
    villain1 = Gru("Gru")
    villain2 = Vector("Vector")

    wizard = Wizard()
    wizard.add_weapon(Weapon("Freeze Gun",50, 11,inf))
    wizard.add_weapon(Weapon("Electric Prod",88,18,5))
    wizard.add_weapon(Weapon("Mega Magnet",92,10,3))
    wizard.add_weapon(Weapon("Kalman Missile",120,20,1))
    wizard.add_shield(Shield("Energy-Projected BarrierGun",20,0.4,inf))
    wizard.add_shield(Shield("Selective Permeability",50,0.9,2))

    wizard.add_weapon(Weapon("Laser Blasters",40,8,inf))
    wizard.add_weapon(Weapon("Plasma Grenades",56,13,8))
    wizard.add_weapon(Weapon("Sonic Resonance Cannon",100,22,3))
    wizard.add_shield(Shield("Energy Net Trap",15,0.32,inf))
    wizard.add_shield(Shield("Quantum Deflector",40,0.8,3))

    round_count = 1
    while villain1.health > 0 and villain2.health > 0 :
        print(f"Round {round_count} :")
        
        weapon1 = wizard.choose_weapon(villain1)
        print(f"{weapon1.name}")
        shield1 = wizard.choose_shield(villain1)
        print(f"{shield1.name}")


        weapon2 = wizard.choose_weapon(villain2)
        print(f"{weapon2.name}")
        shield2 = wizard.choose_shield(villain2)
        print(f"{shield2.name}")

        villain1.use_weapon(villain2,weapon1)
        villain1.use_shield(shield1)

        villain2.use_weapon(villain1,weapon2)
        villain2.use_shield(shield2)

        time.sleep(3)

        print(f"{villain1.name} health : {villain1.health}")
        print(f"{villain2.name} health : {villain2.health}")

        round_count += 1
    
    if villain1.health <= 0:
        print(f"{villain2.name} Wins!")
    else:
        print(f"{villain1.name} Wins!")

simulate_battle()