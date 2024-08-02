#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c[4] = {};
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        ++c[x];
    }

    double pr[c[1] + c[2] + c[3] + 1][c[2] + c[3] + 1][c[3] + 1] = {};
    pr[c[1]][c[2]][c[3]] = 1.0;

    double ev[c[1] + c[2] + c[3] + 1][c[2] + c[3] + 1][c[3] + 1] = {};

    for(int thr = c[3]; thr >= 0; --thr) {
        for(int tw = c[2] + c[3]; tw >= 0; --tw) {
            for(int on = c[1] + c[2] + c[3]; on >= 0; --on) {

                // calculating probability
                if(pr[on][tw][thr] != 0 && on + tw + thr > 0) {
                    const double& me = pr[on][tw][thr];
                    const double sum = on + tw + thr;

                    const double succ = (double) sum / n;
                    if(thr) {
                        pr[on][tw + 1][thr - 1] += me * (double) thr / sum;
                    }
                    if(tw) {
                        pr[on + 1][tw - 1][thr] += me * (double) tw / sum;
                    }
                    if(on) {
                        pr[on - 1][tw][thr]     += me * (double) on / sum;
                    }
                }
                
                // calculating ev
                if(1) {
                    double num = 0, den = 0;

                    double e, p, q;
                    double sum = (on + tw + thr);

                    // from {on, tw - 1, thr + 1}
                    if(thr + 1 <= c[3] && tw > 0) {
                        e = ev[on][tw - 1][thr + 1];
                        p = pr[on][tw - 1][thr + 1];
                        q = (double) (thr + 1) / sum;

                        num += (e + n / sum) * q * p;
                        den += q * p;
                    }

                    // from {on - 1, tw + 1, thr}
                    if(tw + 1 <= c[2] + c[3] && on > 0) {
                        e = ev[on - 1][tw + 1][thr];
                        p = pr[on - 1][tw + 1][thr];
                        q = (double) (tw + 1) / sum;

                        num += (e + n / sum) * q * p;
                        den += q * p;
                    }

                    // from {on + 1, tw, thr}
                    if(on + 1 <= c[1] + c[2] + c[3]) {
                        e = ev[on + 1][tw][thr];
                        p = pr[on + 1][tw][thr];
                        q = (double) (on + 1) / (sum + 1);

                        num += (e + n / (sum + 1)) * q * p;
                        den += q * p;
                    }

                    if(den != 0) {
                        ev[on][tw][thr] += num / den;
                    }
                }
            }
        }
    }

    cout << setprecision(12) << ev[0][0][0];
}
