package invasic.util;

import x10.util.ArrayList;
import x10.util.Collection;

public class PlaceSequence implements Sequence[Place] {
	
	private val list:ArrayList[Place] = new ArrayList[Place]();
	
	public def this(set:Collection[Place]) {
		for(item in set) {
			var i:Int = 0;
			while(i < list.size() && item.id() > list.get(i).id() ) {
				i++;
			}
			list.addBefore(i, item);
		}
	}

	public operator this(i:Int):Place {
	    return list.get(i);
	}
	
	public def iterator():Iterator[Place] {
	    return list.iterator();
	}

	public property def size():Int {
	    return list.size();
	}

}
