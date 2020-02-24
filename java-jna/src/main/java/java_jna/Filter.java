package java_jna;
import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Pointer;

class Filter{
    private Pointer ref = null;
    private Filter() {}

    static private interface CLibrary extends Library {
        CLibrary INSTANCE = (CLibrary) Native.loadLibrary("jni-demo", CLibrary.class);

        Pointer create_jna_filter(String conf);
        boolean filter_init(Pointer ref, String conf);
        boolean filter_filter(Pointer ref, String conf, int len);
        void filter_destroy(Pointer ref);
    }


    /**
     * init the filter
     * @param conf
     * @throws Exception
     */
    public void init(String conf) throws Exception {
        if (CLibrary.INSTANCE.filter_init(ref, conf)) {
            throw new RuntimeException("init failed");
        }
    }

    /**
     * filter the data
     * @param data, string representation of long
     * @return
     * @throws Exception
     */
    public boolean filter(String data) throws Exception {
        return CLibrary.INSTANCE.filter_filter(ref, data, data.length());
    }

    /**
     * destroy the filter, do not use it again after destroy
     */
    public void destroy() {
        CLibrary.INSTANCE.filter_destroy(ref);
    }

    public static Filter create(String name) throws Exception {
        Filter filter = new Filter();
        filter.ref = CLibrary.INSTANCE.create_jna_filter(name);
        if (filter.ref == null) {
            return null;
        }
        return filter;
    }
}
