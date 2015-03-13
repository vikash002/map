#include <iostream>
#include <algorithm>
#include <list>
#include <cstdlib>

using namespace std;

template <typename T1, typename T2>
struct node
{
		T1 first;
		T2 second;
		int h;
		node<T1, T2>* left;
		node<T1, T2>* right;
};

template <typename T1, typename T2>
class map_iterator
{
		public:
		node<T1, T2>* p;
		node<T1, T2>* root;
		map_iterator(node<T1, T2>* p1, node<T1, T2>* root1);
		map_iterator();
		bool operator!=(map_iterator<T1, T2> ob);
		bool operator==(map_iterator<T1, T2> ob);
		map_iterator<T1, T2> operator++();
		const map_iterator<T1, T2> operator++(int);
		map_iterator<T1, T2> operator--();
		const map_iterator<T1, T2> operator--(int);
		node<T1, T2> operator*();
		node<T1, T2>* operator->();
};

template <typename T1, typename T2>
map_iterator<T1, T2> :: map_iterator()
{
		p = root = NULL;
}

template <typename T1, typename T2>
map_iterator<T1, T2> :: map_iterator(node<T1, T2>* p1, node<T1, T2>* root1)
{
		p = p1;
		root = root1;
}

template <typename T1, typename T2>
bool map_iterator<T1, T2> :: operator!=(map_iterator<T1, T2> ob)
{
		return this->p != ob.p;
}

template <typename T1, typename T2>
bool map_iterator<T1, T2> :: operator==(map_iterator<T1, T2> ob)
{
		return this->p == ob.p;
}

template <typename T1, typename T2>
map_iterator<T1, T2> map_iterator<T1, T2> :: operator++()
{
		if (p->right != NULL) {
				p = p->right;
				while (p->left != NULL)
						p = p->left;
				return *this;
		}
		else {
			node<T1, T2>* q = root;
			node<T1, T2>* suc = NULL;

			while (q != NULL) {		
				if (q->first > p->first) {
						suc = q;
						q = q->left;
				}
				else if (q->first < p->first)
						q = q->right;
				else		
						break;
			}
			p = suc;
			return *this;

		}
}

template <typename T1, typename T2>
const map_iterator<T1, T2> map_iterator<T1, T2> :: operator++(int)
{
		map_iterator<T1, T2> obj = *this;
		if (p->right != NULL) {
				p = p->right;
				while (p->left != NULL)
						p = p->left;
				return obj;
		}
		else {
			node<T1, T2>* q = root;
			node<T1, T2>* suc = NULL;

			while (q != NULL) {		
				if (q->first > p->first) {
						suc = q;
						q = q->left;
				}
				else if (q->first < p->first)
						q = q->right;
				else		
						break;
			}
			p = suc;
			return obj;

		}
}

template <typename T1, typename T2>
map_iterator<T1, T2> map_iterator<T1, T2> :: operator--()
{
		if (p->left != NULL) {
				p = p->left;
				while (p->right != NULL)
						p = p->right;
				return *this;
		}
		else {
			node<T1, T2>* q = root;
			node<T1, T2>* suc = NULL;

			while (q != NULL) {		
				if (q->first < p->first) {
						suc = q;
						q = q->right;
				}
				else if (q->first > p->first)
						q = q->left;
				else		
						break;
			}
			p = suc;
			return *this;

		}
}

template <typename T1, typename T2>
const map_iterator<T1, T2> map_iterator<T1, T2> :: operator--(int)
{
		map_iterator<T1, T2> obj = *this;
		if (p->left != NULL) {
				p = p->left;
				while (p->right != NULL)
						p = p->right;
				return obj;
		}
		else {
			node<T1, T2>* q = root;
			node<T1, T2>* suc = NULL;

			while (q != NULL) {		
				if (q->first < p->first) {
						suc = q;
						q = q->right;
				}
				else if (q->first > p->first)
						q = q->left;
				else		
						break;
			}
			p = suc;
			return obj;

		}
}

template <typename T1, typename T2>
node<T1, T2> map_iterator<T1, T2> :: operator*()
{
		return *p;
}

template <typename T1, typename T2>
node<T1, T2>* map_iterator<T1, T2> :: operator->()
{
		return p;
}

template <typename T1, typename T2>
class avl
{
		public:
		typedef size_t size_type;
		typedef map_iterator<T1, T2> iterator;
		typedef pair< iterator, bool> pl;
		typedef map_iterator<T1, T2> const_iterator;
		node<T1, T2>* root;
		size_type sz;
		avl();
		avl(avl<T1, T2>& obj);
		avl<T1, T2>& operator=(avl<T1, T2>& obj);
		~avl();
		bool operator==(avl<T1, T2>& obj);
		bool operator!=(avl<T1, T2>& obj);
		bool operator<(avl<T1, T2>& obj);
		bool operator>(avl<T1, T2>& obj);
		bool operator<=(avl<T1, T2>& obj);
		bool operator>=(avl<T1, T2>& obj);
		T2& operator[](T1 x);
		void swap(avl<T1, T2> &ob);
		size_type  size() const;
		size_type max_size() const;
		bool empty() const;
		iterator begin();
		iterator end();
		node<T1, T2>* make(T1 key, T2 val);
		int height(node<T1, T2>* &p);
		void setheight(node<T1, T2>* &r);
		int getbalance(node<T1, T2>* &r);
		void rightrotate(node<T1, T2>* &r);
		void leftrotate(node<T1, T2>* &r);
		pl insert(pair<T1, T2> pa);
		iterator find(T1 x);
		void delet(T1 x);
		pl inst(  node<T1, T2>* &p, T1 key, T2 val);
		void del(node<T1, T2>* &r, T1 x);
		void traverse(node<T1, T2>* &p, list<pair<T1, T2> > &lst);
};

template <typename T1, typename T2>
avl<T1, T2> :: avl()
{
	 root = NULL;
	 sz = 0;
}

template <typename T1, typename T2>
avl<T1, T2> :: avl(avl<T1, T2>& ob)
{
		this->root = ob.root;
		this->sz = ob.sz;
}

template <typename T1, typename T2>
avl<T1, T2>& avl<T1, T2> :: operator=(avl<T1, T2>& obj)
{
		this->root = obj.root;
		return *this;
}

template <typename T1, typename T2>
avl<T1, T2> :: ~avl()
{
		root = NULL;
}

template <typename T1, typename T2>
bool avl<T1, T2> :: operator==(avl<T1, T2>& obj)
{
		list < pair<T1, T2> > l1, l2;
		traverse(obj.root, l1);
		traverse(this->root, l2);

		return l1 == l2;
}
		
template <typename T1, typename T2>
bool avl<T1, T2> :: operator!=(avl<T1, T2>& obj)
{
		list < pair<T1, T2> > l1, l2;
		traverse(obj.root, l2);
		traverse(this->root, l1);

		return l1 != l2;
}

template <typename T1, typename T2>
bool avl<T1, T2> :: operator<(avl<T1, T2>& obj)
{
		list < pair<T1, T2> > l1, l2;
		traverse(obj.root, l2);
		traverse(this->root, l1);

		return l1 < l2;
}

template <typename T1, typename T2>
bool avl<T1, T2> :: operator>(avl<T1, T2>& obj)
{
		list < pair<T1, T2> > l1, l2;
		traverse(obj.root, l2);
		traverse(this->root, l1);

		return l1 > l2;
}

template <typename T1, typename T2>
bool avl<T1, T2> :: operator<=(avl<T1, T2>& obj)
{
		list < pair<T1, T2> > l1, l2;
		traverse(obj.root, l2);
		traverse(this->root, l1);

		return l1 <= l2;
}

template <typename T1, typename T2>
bool avl<T1, T2> :: operator>=(avl<T1, T2>& obj)
{
		list < pair<T1, T2> > l1, l2;
		traverse(obj.root, l2);
		traverse(this->root, l1);

		return l1 >= l2;
}

template <typename T1, typename T2>
void avl<T1, T2> :: swap(avl<T1, T2> &obj)
{
		node<T1, T2>* p = obj.root;
		obj.root = this->root;
		this->root = p;
}

template <typename T1, typename T2>
size_t avl<T1, T2> :: size() const
{
		return sz;
}

template <typename T1, typename T2>
size_t avl<T1, T2> :: max_size() const
{
		return 461168601842738790;
}

template <typename T1, typename T2>
bool avl<T1, T2> :: empty() const
{
		return sz == 0;
}

template <typename T1, typename T2>
map_iterator<T1, T2> avl<T1, T2> :: begin()
{
		 iterator it;
		 it.p = root;
		 while (it.p->left != NULL)
				 it.p = it.p->left;
		it.root = root;
	
		return it;		 
}

template <typename T1, typename T2>
map_iterator<T1, T2> avl<T1, T2> :: end()
{
		 iterator it;
		 it.p = root;
		 while(it.p != NULL){
			 it.p = it.p->right;
		 }
		 it.root = root;

		return it;
}

template <typename T1, typename T2>
node<T1, T2>* avl<T1,T2> :: make(T1 key, T2 val)
{
	node<T1, T2>* r = new node<T1, T2>;
	r->first = key;
	r->second = val;
	r->h = 1;
	r->left = NULL;
	r->right = NULL;
}

template <typename T1, typename T2>
int avl<T1,T2> :: height(node<T1, T2>* &p)
{
		if (p == NULL)
				return 0;
		
		return p->h;
}

template <typename T1, typename T2>
void avl<T1, T2> :: setheight(node<T1, T2>* &r)
{
		if (r == 0)
				return;

		r->h = 1 + max( height(r->left), height(r->right));
}

template <typename T1, typename T2>
int avl<T1,T2> :: getbalance(node<T1, T2>* &r)
{
		if (r == NULL)
				return 0;
		return height(r->left) - height(r->right);
}

template <typename T1, typename T2>
void avl<T1, T2> :: rightrotate(node<T1, T2>* &r)
{
		node<T1, T2>* z = r;
		node<T1, T2>* y = r->left;
		node<T1, T2>* tmp = y->right;

		r = y;
		r->right = z;
		z->left = tmp;

		setheight(r->right);
		setheight(r);
		return;
}

template <typename T1, typename T2>
void avl<T1, T2> :: leftrotate(node<T1, T2>* &r)
{
		node<T1, T2>* z = r;
		node<T1, T2>* y = r->right;
		node<T1, T2>* tmp = y->left;

		r = y;
		r->left = z;
		z->right = tmp;

		setheight(r->left);
		setheight(r);
		return;
}

template <typename T1, typename T2>
 pair<typename avl<T1, T2> ::iterator, bool> avl<T1, T2> :: insert(pair<T1, T2> pa)
{
	pl ap = inst( root, pa.first, pa.second);
	if (ap.second)
			sz++;
	return ap;
}

template <typename T1, typename T2>
typename avl<T1, T2> :: iterator avl<T1, T2> :: find(T1 x)
{
		node<T1, T2>* tmp = root;

		while (tmp != NULL) {
			if (tmp->first < x)
					tmp = tmp->right;
			else if (tmp->first > x)
					tmp = tmp->left;
			else
					break;
		}
		return iterator(tmp, root);
}

template <typename T1, typename T2>
T2& avl<T1,T2> :: operator[](T1 x)
{
		iterator it = find(x);
		pair<iterator, bool> pa;
		if (it.p == NULL) {
				pa = inst(root, x,x);
				cout << pa.first->second << endl;
				return pa.first->second;
		}
		else 
				return it->second;
}

template <typename T1, typename T2>
void avl<T1, T2> :: delet(T1 x)
{
		del(root, x);
		sz--;
}

template <typename T1, typename T2>
pair<typename avl<T1,T2> :: iterator, bool> avl<T1, T2> :: inst(  node<T1, T2>* &p, T1 key, T2 val)
{
		if (p == NULL) {
				p = make(key, val);
				return pl(iterator(p,root), true);
		}
		
		bool flag = true;
		pl ap;
		if (p->first < key)
				 ap = inst( p->right, key, val);
		else if (p->first > key)
				 ap =  inst( p->left, key, val);
		else
				flag = false;

		setheight(p);		

		int bal = getbalance(p);
		node<T1, T2>* tmp;

		if (bal == 2) {	
			tmp = p->left;
			if (height(tmp->left) >= height(tmp->right) ) 
					rightrotate(p);
			else {
					leftrotate(p->left);
					rightrotate(p);
			}
		}
		else if (bal == -2) {
			tmp = p->right;
			if (height(tmp->right) >= height(tmp->left))
					leftrotate(p);
			else {
					rightrotate(p->right);
					leftrotate(p);
			}
		}
		return (flag) ? ap : pl(iterator(p,root), flag);
}

template <typename T1, typename T2>
void avl<T1, T2> :: del(node<T1, T2>* &r, T1 x)
{
		node<T1, T2>* tmp;
		int bal;
		if (r == NULL)
				return;

		if (r->first == x) {
				if (r->left == NULL && r->right == NULL) 
						r = NULL;
				else if (r->left != NULL && r->right != NULL) {
						tmp = r->right;

						while (tmp->left != NULL) 
								tmp = tmp->left;

						swap(r->first, tmp->first);
						del(r->right, x);		
				}
				else if (r->left != NULL && r->right == NULL) 
						r = r->left;
				else
						r = r->right;
		}
		else if (r->first <= x)
				del(r->right, x);
		else
				del(r->left, x);
	
		if (r != NULL) {	
				setheight(r->left);	
				setheight(r->right);	
				setheight(r);
		}

		 bal = getbalance(r);
		if (bal == 2) {	
			tmp =r->left;
			if (height(tmp->left) >= height(tmp->right) ) 
					rightrotate(r);
			else {
					leftrotate(r->left);
					rightrotate(r);
			}
		}
		else if (bal == -2) {
			tmp = r->right;
			if (height(tmp->right) >= height(tmp->left))
					leftrotate(r);
			else {
					rightrotate(r->right);
					leftrotate(r);
			}
		}
}

template <typename T1, typename T2>
void avl<T1, T2> :: traverse(node<T1, T2>* &p, list< pair<T1, T2> >&lst)
{
		if (p != NULL) {
				traverse(p->left, lst);
				//printf("%d->%d ", p->first, p->h);
				lst.push_back(pair<T1, T2>(p->first, p->second));
				traverse(p->right, lst);
		}
}

int main()
{
		avl<int, int> h;
		avl<int, int> :: iterator it, it1;
		pair< avl<int, int> :: iterator, bool> ap;
		int n, opt, j;

		for (int i = 0; i < 10; i++) {
				j = rand()%100;
				h.insert(pair<int, int>(j, j));
		}
		for ( it = h.begin(); it != h.end(); it++)
			cout << it->first << "->" << it->second <<  " " ;
		cout << endl;	
	
		/*while (cin >> n)  {
				cin >> opt;
				if (opt) {
					 //ap = h.insert(pair<int, int> (n, n));
					 h[n] = opt;
					 it = h.begin(); }
					//cout << ap.first->first << "->" <<  ap.first->second << " " << ap.second << endl; }
				else  {
					it = h.find(n);
					h[n] = n+1;
				}
					it1 = it;
				for (; it != h.end(); ++it)			
					cout << it->first << "->" << it->second <<  " " ;
			cout << endl;
				for (; it1 != h.begin(); --it1)	
					cout << it1->first << "->" << it1->second <<  " "  ;
			cout << it1->first << "->" << it1->second <<  " " << endl;
			//	h.delet(n);
		}
		int j;
               */
		for ( it = h.end(); it != h.begin(); it--)
		{	
			cout << it->first << "->" << it->second <<  " " ;
			it->first += 10;
		}
		cout << endl;

		return 0;
}

