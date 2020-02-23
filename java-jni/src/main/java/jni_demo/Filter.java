package jni_demo;
import java.lang.*;

class Filter{
    private long ref = 0;

    private static native long create_jni_filter(String name) throws Exception;

    private static native void init(long ref, String conf) throws Exception;

    private static native boolean filter(long ref, byte[] data);

    private static native void destroy(long ref);

    /**
     * init the filter
     * @param conf
     * @throws Exception
     */
    public void init(String conf) throws Exception {
        init(ref, conf);
    }

    /**
     * filter the data
     * @param data, string representation of long
     * @return
     * @throws Exception
     */
    public boolean filter(byte[] data) throws Exception {
        return filter(ref, data);
    }

    /**
     * destroy the filter, do not use it again after destroy
     */
    public void destroy() {
        destroy(ref);
        ref = 0;
    }

    public static Filter create(String name) throws Exception {
        Filter filter = new Filter();
        long ref = create_jni_filter(name);
        if (ref == 0) {
            return null;
        }
        filter.ref = ref;
        return filter;
    }

    static {
        System.loadLibrary("jni-demo");
    }
}