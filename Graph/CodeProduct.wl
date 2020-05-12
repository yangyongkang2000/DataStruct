(*Module[{G = 
   Graph[(Flatten[
          Flatten[Table[{#1, n}, {n, 1, #1}] & /@ Range[#1], 
            1] /. {x_, 
             y_} :> (x*(x - 1)/2 + 
                 y \[DirectedEdge] # & /@ (x*(x + 1)/2 + 
                y + {0, 1}))]~Join~
         Table[#1*(#1 + 1)/2 + 
            n \[DirectedEdge] (#1 + 1)*(#1 + 2)/2 + 1, {n, 
           1, #1 + 1}]) &@#] &, V, 
  edgeweight = 
   Join[Riffle[#[[;; -101]], #[[;; -101]]], #[[-100 ;;]]] &@
    ToExpression@
     StringSplit@Import["/Users/yangyongkang/Desktop/b.txt"], list, 
  t = 1, str = "/Users/yangyongkang/Desktop/C/Graph/"}, 
 V = (#[[All, 2]] & /@ 
    Values[GroupBy[List @@@ EdgeList@G@99, #[[1]] &]]);
 list = MapThread[Join, {{#} & /@ Range[Length@V], V}];
 Export[str <> "make.txt", 
  "void make(Graph G)\n{List tmp;\nG[0]->Next=NULL;\nG[0]->V=0;\n\
G[0]->w=0;\n" <> 
   StringJoin@
    Table["tmp=G[" <> ToString[i] <> "];\n" <> 
      StringJoin@
       Table["tmp->V=" <> ToString[list[[i, j]]] <> ";\ntmp->w=" <> 
         ToString[edgeweight[[t++]]] <> 
         ";\ntmp=(tmp->Next=(List)malloc(sizeof(struct Node)));\n", \
{j, 1, Length@list[[i]] - 1}] <> "tmp->V=" <> 
      ToString[Last@list[[i]]] <> ";\ntmp->Next=NULL;\n", {i, 1, 
      Length@V}] <> "tmp=G[" <> ToString[Length@V + 1] <> 
   "];\ntmp->V=" <> ToString[Length@V + 1] <> 
   ";\ntmp->w=0;\ntmp->Next=NULL;\n" <> "}"];
 Run["mv " <> str <> "make.txt" <> " " <> str <> "make.h"];]*)
 Module[{G = 
   Graph[(Flatten[
          Flatten[Table[{#1, n}, {n, 1, #1}] & /@ Range[#1], 
            1] /. {x_, 
             y_} :> (x*(x - 1)/2 + 
                 y \[DirectedEdge] # & /@ (x*(x + 1)/2 + 
                y + {0, 1}))]~Join~
         Table[#1*(#1 + 1)/2 + 
            n \[DirectedEdge] (#1 + 1)*(#1 + 2)/2 + 1, {n, 
           1, #1 + 1}]) &@#] &, V1, V, edgeweight, edgeweightlist, 
  list, t = 1, str = "/Users/yangyongkang/Desktop/C/Graph/"}, 
 edgeweight[n_Integer, file_String] := 
  Join[Riffle[#[[;; -n - 1]], #[[;; -n - 1]]], #[[-n ;;]]] &@
   ToExpression@StringSplit@Import[file]; 
 V1 = (#[[All, 2]] & /@ 
     Values[GroupBy[List @@@ EdgeList@G@(# - 1), #[[1]] &]]) &; 
 V = V1[100];
 list = MapThread[Join, {{#} & /@ Range[Length@V], V}]; 
 edgeweightlist = edgeweight[100, "/Users/yangyongkang/Desktop/b.txt"];
 Export[str <> "make.txt", 
  "void make(Graph G)\n{List tmp;\nG[0]->Next=NULL;\nG[0]->V=0;\n\
G[0]->w=0;\n" <> 
   StringJoin@
    Table["tmp=G[" <> ToString[i] <> "];\n" <> 
      StringJoin@
       Table["tmp->V=" <> ToString[list[[i, j]]] <> ";\ntmp->w=" <> 
         ToString[edgeweightlist[[t++]]] <> 
         ";\ntmp=(tmp->Next=(List)malloc(sizeof(struct Node)));\n", \
{j, 1, Length@list[[i]] - 1}] <> "tmp->V=" <> 
      ToString[Last@list[[i]]] <> ";\ntmp->Next=NULL;\n", {i, 1, 
      Length@V}] <> "tmp=G[" <> ToString[Length@V + 1] <> 
   "];\ntmp->V=" <> ToString[Length@V + 1] <> 
   ";\ntmp->w=0;\ntmp->Next=NULL;\n" <> "}"];
 Run["mv " <> str <> "make.txt" <> " " <> str <> "make.h"];]