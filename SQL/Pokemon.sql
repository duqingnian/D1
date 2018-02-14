-- To run this file after saving, use the'@' symbol followed by the location of the file (and file name) in your area...

-- Eg:             @\\coventry\csv\Students\Personal\k\thankik\Yr1\ALL\SQL\Pokemon

-- THE TABLE MUST BE DROPPED BEFORE BEING CREATED

drop table Type;
drop table PokemonTable;
drop table AbilityIdent;
drop table Ability;
drop table Power;

-------------------- TYPE ----------------------

-- CREATE THE TABLE

create table Type (
   TypeID int not null,
   Type varchar(25),
   Weakness varchar(25)
);

--- "NOT NULL" specifies that there must be a value in the column of the table - it cannot be empty.
--- "VARCHAR(25)" means that the character length in the specific column of the table is a maximum of 25 characters.
--- "DESCRIBE TYPE" will specify the table type being created (varchar, not null etc).

Describe Type;   
insert into Type values (1, 'EARTH', 'WATER');
insert into Type values (2, 'GRASS', 'FIRE');
insert into Type values (3, 'FIRE', 'WATER');
insert into Type values (4, 'ELECTRIC', 'EARTH');
insert into Type values (5, 'WIND', 'WATER');

--- "SELECT * FROM TYPE" will throw the table 'Type' and its contents onto the terminal.

select * from Type;



------------------- POKEMONTABLE ----------------------



-- CREATE THE TABLE

create table PokemonTable (
   PokemonID int not null,
   TypeID int not null, 
   Name varchar(25),
   PowerID int not null
);

Describe PokemonTable;

insert into PokemonTable values (1, 1, 'CATTER', 1);
insert into PokemonTable values (2, 2, 'LEMONGRASS', 2);
insert into PokemonTable values (3, 3, 'PYRO', 3);
insert into PokemonTable values (4, 4, 'THUNDERSHOCK',4);
insert into PokemonTable values (5, 5, 'ZIZI',5);


select * from PokemonTable;



------------------- ABILITYIDENT ----------------------


-- CREATE THE TABLE

create table AbilityIdent (
   PokemonID int not null,
   AbilityID int not null 
);

Describe AbilityIdent;

insert into AbilityIdent values (1, 1);
insert into AbilityIdent values (2, 2);
insert into AbilityIdent values (3, 3);
insert into AbilityIdent values (4, 4);
insert into AbilityIdent values (5, 5);

select * from AbilityIdent;



------------------- ABILITY ----------------------


-- CREATE THE TABLE

create table Ability (
   AbilityID int not null,
   Ability_Name varchar(25),
   Damage int not null,
   Mana int not null
);

Describe Ability;

insert into Ability values (1, 'SCRATCH', 10, 0);
insert into Ability values (2, 'MEOW', 20, 20);
insert into Ability values (3, 'TAIL WHIP', 45, 55);
insert into Ability values (4, 'NUT THROW', 17, 0);
insert into Ability values (5, 'BITE', 27, 20);
insert into Ability values (6, 'HURRICANE', 55, 50);
insert into Ability values (7, 'SLASH', 10, 0);
insert into Ability values (8, 'EMBER', 30, 20);
insert into Ability values (9, 'LEAF BOMB', 55, 45);
insert into Ability values (10, 'CLAW', 10, 0);
insert into Ability values (11, 'BOLT', 30, 20);
insert into Ability values (12, 'LIGHTNINGBLAST', 60, 50);

select * from Ability;





------------------- POWER ----------------------

-- CREATE THE TABLE

create table Power (
   PowerID int not null,
   Lvl int not null,
   HP int not null,                 
   MaxHP int not null,           
   XP int not null,                 
   Agility int not null,            
   Strength int not null,           
   MaxMana int not null            
);

Describe Power;

--- EVERYTHING BELOW HAS BEEN WRITTEN AS IF THERE ARE 20 LEVELS OF EACH POKEMON - THIS CAN BE CHANGED IF NEEDED

---CATTER---

insert into Power values (1, 1, 90, 90, 5, 60, 12, 100);
insert into Power values (1, 2, 90, 90, 10, 67, 20, 100);
insert into Power values (1, 3, 91, 91, 15, 70, 25, 100);
insert into Power values (1, 4, 91, 91, 20, 73, 31, 100);
insert into Power values (1, 5, 92, 92, 25, 77, 36, 100);
insert into Power values (1, 6, 92, 92, 30, 79, 43, 100);
insert into Power values (1, 7, 93, 93, 35, 82, 47, 100);
insert into Power values (1, 8, 93, 93, 40, 84, 53, 100);
insert into Power values (1, 9, 94, 94, 45, 85, 57, 100);
insert into Power values (1, 10, 94, 94, 50, 88, 65, 100);
insert into Power values (1, 11, 95, 95, 55, 89, 68, 100);
insert into Power values (1, 12, 95, 95, 60, 91, 73, 100);
insert into Power values (1, 13, 96, 96, 65, 91, 76, 100);
insert into Power values (1, 14, 96, 96, 70, 91, 78, 100);
insert into Power values (1, 15, 97, 97, 75, 92, 80, 100);
insert into Power values (1, 16, 97, 97, 80, 92, 82, 100);
insert into Power values (1, 17, 98, 98, 85, 93, 85, 100);
insert into Power values (1, 18, 98, 98, 90, 94, 88, 100);
insert into Power values (1, 19, 99, 99, 95, 95, 92, 100);
insert into Power values (1, 20, 99, 99, 100, 96, 93, 100);


---LEMONGRASS---

insert into Power values (2, 1, 75, 75, 5, 65, 17, 95);
insert into Power values (2, 2, 78, 78, 10, 70, 25, 95);
insert into Power values (2, 3, 80, 80, 15, 74, 30, 95);
insert into Power values (2, 4, 83, 83, 20, 65, 36, 95);
insert into Power values (2, 5, 85, 85, 25, 69, 41, 95);
insert into Power values (2, 6, 87, 87, 30, 73, 48, 95);
insert into Power values (2, 7, 88, 88, 35, 76, 51, 96);
insert into Power values (2, 8, 89, 89, 40, 79, 53, 96);
insert into Power values (2, 9, 90, 90, 45, 82, 56, 95);
insert into Power values (2, 10, 91, 91, 50, 84, 60, 95);
insert into Power values (2, 11, 91, 91, 55, 86, 67, 95);
insert into Power values (2, 12, 92, 92, 60, 88, 72, 95);
insert into Power values (2, 13, 93, 93, 65, 88, 74, 95);
insert into Power values (2, 14, 93, 93, 70, 89, 76, 95);
insert into Power values (2, 15, 94, 94, 75, 90, 79, 95);
insert into Power values (2, 16, 94, 95, 80, 91, 83, 95);
insert into Power values (2, 17, 95, 95, 85, 92, 85, 95);
insert into Power values (2, 18, 96, 96, 90, 93, 89, 95);
insert into Power values (2, 19, 97, 97, 95, 94, 93, 96);
insert into Power values (2, 20, 98, 98, 100, 95, 94, 97);


---PYRO---

insert into Power values (3, 1, 80, 80, 5, 70, 18, 90);
insert into Power values (3, 2, 83, 83, 10, 74, 21, 90);
insert into Power values (3, 3, 85, 85, 15, 79, 25, 90);
insert into Power values (3, 4, 87, 87, 20, 70, 30, 92);
insert into Power values (3, 5, 89, 89, 25, 74, 35, 90);
insert into Power values (3, 6, 89, 89, 30, 77, 40, 90);
insert into Power values (3, 7, 90, 90, 35, 79, 46, 91);
insert into Power values (3, 8, 90, 90, 40, 81, 50, 91);
insert into Power values (3, 9, 91, 91, 45, 83, 55, 90);
insert into Power values (3, 10, 91, 91, 50, 85, 59, 90);
insert into Power values (3, 11, 92, 92, 55, 87, 63, 91);
insert into Power values (3, 12, 93, 93, 60, 89, 73, 91);
insert into Power values (3, 13, 93, 93, 65, 90, 77, 92);
insert into Power values (3, 14, 94, 94, 70, 90, 80, 92);
insert into Power values (3, 15, 94, 94, 75, 91, 83, 92);
insert into Power values (3, 16, 95, 95, 80, 92, 86, 92);
insert into Power values (3, 17, 95, 95, 85, 93, 88, 92);
insert into Power values (3, 18, 96, 96, 90, 94, 92, 92);
insert into Power values (3, 19, 97, 97, 95, 95, 93, 94);
insert into Power values (3, 20, 98, 98, 100, 96, 94, 95);

---THUNDERSHOCK---

insert into Power values (4, 1, 80, 80, 5, 75, 20, 90);
insert into Power values (4, 2, 83, 83, 10, 78, 24, 90);
insert into Power values (4, 3, 86, 86, 15, 82, 29, 92);
insert into Power values (4, 4, 88, 88, 20, 75, 34, 94);
insert into Power values (4, 5, 89, 89, 25, 78, 37, 90);
insert into Power values (4, 6, 90, 90, 30, 80, 40, 90);
insert into Power values (4, 7, 91, 91, 35, 82, 46, 91);
insert into Power values (4, 8, 91, 91, 40, 83, 51, 91);
insert into Power values (4, 9, 91, 91, 45, 85, 57, 90);
insert into Power values (4, 10, 91, 91, 50, 87, 63, 90);
insert into Power values (4, 11, 92, 92, 55, 89, 67, 91);
insert into Power values (4, 12, 93, 93, 60, 90, 70, 91);
insert into Power values (4, 13, 94, 94, 65, 91, 73, 92);
insert into Power values (4, 14, 94, 94, 70, 91, 76, 92);
insert into Power values (4, 15, 94, 94, 75, 91, 79, 92);
insert into Power values (4, 16, 95, 95, 80, 92, 82, 92);
insert into Power values (4, 17, 96, 95, 85, 93, 84, 92);
insert into Power values (4, 18, 96, 96, 90, 94, 87, 92);
insert into Power values (4, 19, 97, 97, 95, 95, 94, 93);
insert into Power values (4, 20, 98, 98, 100, 96, 95, 94);


---ZIZI---

insert into Power values (5, 1, 50, 50, 5, 80, 20, 80);
insert into Power values (5, 2, 54, 54, 10, 86, 26, 80);
insert into Power values (5, 3, 59, 59, 15, 87, 30, 82);
insert into Power values (5, 4, 63, 63, 20, 88, 35, 84);
insert into Power values (5, 5, 67, 67, 25, 89, 40, 80);
insert into Power values (5, 6, 70, 70, 30, 90, 45, 80);
insert into Power values (5, 7, 76, 76, 35, 91, 47, 82);
insert into Power values (5, 8, 79, 79, 40, 91, 52, 82);
insert into Power values (5, 9, 83, 83, 45, 92, 55, 80);
insert into Power values (5, 10, 85, 85, 50, 92, 58, 80);
insert into Power values (5, 11, 87, 87, 55, 93, 60, 82);
insert into Power values (5, 12, 88, 88, 60, 94, 64, 84);
insert into Power values (5, 13, 90, 90, 65, 94, 68, 85);
insert into Power values (5, 14, 91, 91, 70, 94, 71, 85);
insert into Power values (5, 15, 92, 92, 75, 94, 74, 85);
insert into Power values (5, 16, 93, 93, 80, 95, 77, 85);
insert into Power values (5, 17, 94, 94, 85, 96, 79, 85);
insert into Power values (5, 18, 95, 95, 90, 97, 83, 85);
insert into Power values (5, 19, 96, 96, 95, 98, 95, 90);
insert into Power values (5, 20, 97, 97, 100, 99, 96, 91)


select * from Power;
