import Control.Monad
import Data.List
 
queens :: Int -> [[Int]]
queens n = map fst $ foldM addQueen ([],[1..n]) [1..n]  where 

  addQueen (y,d) _ = [(x:y, delete x d) | x <- d, safe x]  where
  
    safe x = and [x /= c + n && x /= c - n | (n,c) <- zip [1..] y]
 
main = mapM_ print $ queens 4
