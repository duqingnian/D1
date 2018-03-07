--Combines Power and PokemonTable
Select P.POWERID      
         , PT.NAME
         , P.LVL
         , P.HP
         , P.MAXHP
         , P.XP
         , P.AGILITY
         , P.STRENGTH
         , P.MAXMANA
      from POWER P,
           PokemonTable PT
     where P.PowerID = PT.PowerID;

--Combines PokemonTable, Ability and AbilityIdent
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

--Combines PokemonTable, Ability, AbilityIdent and Type
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


--Combines PokemonTable, Ability, AbilityIdent, Type and Power
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
