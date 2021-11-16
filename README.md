# FFXIV Automatic Timeline creator

# Notes
1. Filter out enemy attack cast instances from ACT log file and create refined output file
2. For now do some output but the end result should be an Excel sheet -> look up CSV format
3. ARGV: Time offset, end/start point and maybe target filter
4. Attack opcodes for later:

Must Haves
- The ability to export all boss casts to a google doc. This should have the name of the cast + the time at which the cast snapshots/finishes.
- Layout of the google doc in columns. (Cast Name) (Time) (Tank 1 Mit) (Tank 2 Mit) (Heal 1 Mit) (Heal 2 Mit) (DPS Mit) (Extra)

Nice to Haves
- Damage type (Raidwide/TankBuster/Selected Players) shown as an extra column.
- Average Damage Dealt for each cast as an extra column.
- Average Damage Dealt to Non-tanks for Raidwide/Selected Player type attacks as an extra column.
- Mitigation Used as an extra column. (We could use this as a separate page to see where we are currently using things and how it affects the damage dealt)

# segments
0 = Opcode
1 = timestamp
2 = ???
3 = name
4 = something related to the attack
5 = attack name
6 = compressed damage value
7 = target name
8 = ???
9-23 = ???
24 = Target current HP
25 = Target MAX HP
26 = target current MP
27 = target MAX MP
28 = target current TP
29 = target MAX TP
30-33 = Coordinates? values are floats
34 = user current HP
35 = user MAX HP
36 = user current MP
37 = user MAX MP
38 = user current TP
39 = user MAX TP
40-> = Something irrelevant I assume
-685.4506|
-621.7594|
34.5|
2.409873|
00014B8E|
0|
9adfc68fb468095551624ce1be214096

# TODO
