-- Joins the PokemonTable and Type table together
Select TYPE.TYPEID
         , TYPE.TYPE
         , TYPE.WEAKNESS
         , POKEMONTABLE.TYPEID
         , POKEMONTABLE.NAME
      from Type,
           PokemonTable
     where Type.TypeID = PokemonTable.TypeID;



-- Joins the PokemonTable and Power tables together
Select P.POWERID      
         , PT.NAME
         , P.LVL
         , P.HP
         , P.MAXHP
         , P.XP
         , P.AGILITY
         , P.STRENGTH
         , P.MAXMANA
      from POWER        P,
           PokemonTable PT
     where P.PowerID = PT.PowerID;


-- Joins the PokemonTable and Ability Tables together
Select P.POKEMONID      
         , P.NAME
         , A.AbilityID
         , A.Damage
         , A.Mana
      from PokemonTable P
           , Ability A
           , AbilityIDENT AI
     where P.PokemonID = AI.PokemonID
       and A.AbilityID = AI.AbilityID 
;




-- Joins Ability - Pokemon - Type 
Select P.POKEMONID      
         , P.NAME
         , A.AbilityID
         , A.Damage
         , A.Mana
         , T.Type
         , T.Weakness
      from PokemonTable P
           , Ability A
           , AbilityIDENT AI
           , Type T
     where P.PokemonID = AI.PokemonID
       and A.AbilityID = AI.AbilityID
       and P.TypeID = T.TypeID
;



-- Joins Ability - Pokemon - Type - Power
Select P.POKEMONID      
         , P.NAME
         , A.AbilityID
         , A.Damage
         , A.Mana
         , T.Type
         , T.Weakness
         , W.PowerID
         , W.Lvl
      from PokemonTable P
           , Ability A
           , AbilityIDENT AI
           , Type T
           , Power W
     where P.PokemonID = AI.PokemonID
       and A.AbilityID = AI.AbilityID
       and P.TypeID = T.TypeID
       and P.PowerID = W.PowerID
;
