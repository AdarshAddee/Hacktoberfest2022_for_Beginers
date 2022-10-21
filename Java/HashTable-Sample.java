package data.structures;

public class HashTable {
    
    Entry[] entries;
    private int size;
    private final Entry NIL = new Entry(null, null);
    
    HashTable(int length){
        entries = new Entry[length]; 
    }
    HashTable(){
        this(11);
    }
    
    
    private class Entry{
        Object key, value;
        
        Entry(Object key, Object value){
            this.key = key;
            this.value = value;
        }
    }

    private int hash(Object key){
        return (key.hashCode() & 0x7FFFFFFF) % entries.length;
    }

    public int size() {
        return size;
    }

    public void put(Object key, Object value) {
        if(size > 0.7F * entries.length)
            rehash();
        
        int h = hash(key);
        for (int i = 0; i < entries.length; i++) {
            int j = (i+h) % entries.length;
            if(entries[j] == null || entries[j] == NIL){
                entries[j] = new Entry(key, value);
                size++; 
                break;
            }
        }
    }

    public Object get(Object key) {
        int h = hash(key);
        for (int i = 0; i < entries.length; i++) {
            
            int j = (h+i) % entries.length;
            
            if(entries[j] == null) break;
            
            if(entries[j] == NIL) continue;
            
            if(entries[j].key.equals(key))
                return entries[j].value;
        }
        return null;
    }

    public Object remove(Object key) {
        
        int h = hash(key);
        
        for (int i = 0; i < entries.length; i++) {
            int j = (i+h) % entries.length;
            
            if(entries[j] == null) break;
            
            if(entries[j].key.equals(key)){
                Object value = entries[j].value;
                entries[j] = NIL;
                size--;
                return value; 
            }
        }
        return null;
    }
    
    private void rehash(){
        Entry[] oldEntries = entries;
        entries = new Entry[2*oldEntries.length+1];
        for (Entry entry : oldEntries) {
            if(entry == null || entry == NIL) continue;
            int h = hash(entry.key);
            for (int j = 0; j < entries.length; j++) {
                int k = (h+j) % entries.length;
                if(entries[k] == null){
                    entries[k] = entry;
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        HashTable tableHash = new HashTable();
        tableHash.put("PK", "Pakistan");
        tableHash.put("IND", "India");
        tableHash.put("USA", "America");
        tableHash.put("GB", "United Kingdom");
        tableHash.remove("GB");
        tableHash.put("PT", "Portugual");
        
        System.out.println(tableHash.get("PK"));
        System.out.println(tableHash.get("IND"));
        System.out.println(tableHash.get("USA"));
        System.out.println(tableHash.get("GB"));
        System.out.println(tableHash.get("PT"));
        System.out.println("Size: " + tableHash.size());
        
    }
}
