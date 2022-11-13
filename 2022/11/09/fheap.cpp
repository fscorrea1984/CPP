insert(h,k) // insert key into heap
meld(makeheap(k))

getmin(h)
return minroot(h)

delete(h,p) // delete from heap from position
decreasekey(h,p,-INF)
deletemin(h)

meld(h1,h2)
list with roots in h1 and h2

minroot(h) = if key(minroot(h1))<(key(minroot(h2)) h1 else h2

decreasekey(h,p,k)
							     key(p) = k
							     if (k < key(minroot(h)))
							       minroot(h) = p
								 if !root(p)
				  if key(parent(p))>key(p)
				  // cut p and add to root list
				  cut(p) = false
				  cascading-cut(h,parent(p))

				  cascading-cut(h,p)
				  // p lost a child
				  if root(p)
				  return
				  if(!cut(p))
				    cut(p) = true
				    else
				      // cut p and add to root list
				      cut(p) = false
					cascading-cut(h,parent(p))
					end if

				  deletemin(h)
				  // remove minroot(h)
				  // get the rest of h and minroot(h) children
				  // reorganize heap
				  // determines the max post M = M(n) of h
				  ri = undef forall 0 <= i <= M
				  forall root r do
					     // remove r from root list
					     d = degree(r)
					       while(rd not undef) do
								     r = link(r,rd)
								       rd = undef
								       d = d + 1
								       end while
				  rd = r
				  end for
				  // define root list by defined entries ri
				  // determine new minroot

				  link(h1,h2)
				  if(key(h1)<key(h2))
				    h = makechild(h1,h2)
				    else
				      h = makechild(h2,h1)
					cut(h1) = false
					cut(h2) = false
					return h
